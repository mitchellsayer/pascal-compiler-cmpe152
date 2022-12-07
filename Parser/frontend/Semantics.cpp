#include <vector>
#include <set>

#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/Symtab.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/type/TypeChecker.h"
#include "intermediate/util/CrossReferencer.h"
#include "ErrorHandlers.h"
#include "Semantics.h"

namespace intermediate { namespace symtab {
    int Symtab::unnamedIndex = 0;
}}

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;
using namespace intermediate::util;

Object Semantics::visitProgram(PascalParser::ProgramContext *ctx)
{
    visit(ctx->programHeader());
    visit(ctx->block()->declarations());
    visit(ctx->block()->compoundStatement());

    CrossReferencer crossReferencer;
    crossReferencer.print(symtabStack);

    return nullptr;
}

Object Semantics::visitProgramHeader(PascalParser::ProgramHeaderContext *ctx)
{
    PascalParser::ProgramIdentifierContext *idCtx = ctx->programIdentifier();
    string programName = idCtx->IDENTIFIER()->getText();

    programId = symtabStack->enterLocal(programName, PROGRAM);
    programId->setRoutineSymtab(symtabStack->push());

    symtabStack->setProgramId(programId);
    symtabStack->getLocalSymtab()->setOwner(programId);

    idCtx->entry = programId;
    return nullptr;
}

Object Semantics::visitConstantDefinition(PascalParser::ConstantDefinitionContext *ctx)
{
    PascalParser::ConstantIdentifierContext *idCtx = ctx->constantIdentifier();
    string constantName = toLowerCase(idCtx->IDENTIFIER()->getText());
    SymtabEntry *constantId = symtabStack->lookupLocal(constantName);

    if (constantId == nullptr){
        PascalParser::ConstantContext *constCtx = ctx->constant();
        Object constValue = visit(constCtx);

        constantId = symtabStack->enterLocal(constantName, CONSTANT);
        constantId->setValue(constValue);
        constantId->setType(constCtx->type);

        idCtx->entry = constantId;
        idCtx->type  = constCtx->type;
    } else {
        error.flag(REDECLARED_IDENTIFIER, ctx);

        idCtx->entry = constantId;
        idCtx->type  = Predefined::integerType;
    }

    constantId->appendLineNumber(ctx->getStart()->getLine());
    return nullptr;
}

Object Semantics::visitConstant(PascalParser::ConstantContext *ctx) {
    if (ctx->IDENTIFIER() != nullptr) {
        string constantName = toLowerCase(ctx->IDENTIFIER()->getText());
        SymtabEntry *constantId = symtabStack->lookup(constantName);

        if (constantId != nullptr) {
            Kind kind = constantId->getKind();
            if (kind != CONSTANT) {
                error.flag(INVALID_CONSTANT, ctx);
            }

            ctx->type  = constantId->getType();
            ctx->value = constantId->getValue();

            constantId->appendLineNumber(ctx->getStart()->getLine());
        }
        else {
            error.flag(UNDECLARED_IDENTIFIER, ctx);
            ctx->type = Predefined::integerType;
            ctx->value = 0;
        }
    }
    else if (ctx->characterConstant() != nullptr) {
        ctx->type = Predefined::charType;
        ctx->value = ctx->getText()[1];
    }
    else if (ctx->stringConstant() != nullptr) {
        string pascalString = ctx->stringConstant()->STRING()->getText();
        string unquoted = pascalString.substr(1, pascalString.length()-2);

        size_t pos = 0;
        while ((pos = unquoted.find("''", pos)) != string::npos) {
            unquoted.replace(pos++, 2, "'");
        }

        pos = 0;
        while ((pos = unquoted.find("\"", pos)) != string::npos) {
            unquoted.replace(pos++, 2, "\\\"");
        }

        ctx->type = Predefined::stringType;
        ctx->value = new string(unquoted);
    } else {
        PascalParser::UnsignedNumberContext *unsignedCtx = ctx->unsignedNumber();

        if (unsignedCtx->integerConstant() != nullptr) {
            ctx->type = Predefined::integerType;
            ctx->value = stoi(ctx->getText());
        } else {
            ctx->type = Predefined::realType;
            ctx->value = stod(ctx->getText());
        }
    }

    return ctx->value;
}

Object Semantics::visitTypeDefinition(PascalParser::TypeDefinitionContext *ctx) {
    PascalParser::TypeIdentifierContext *idCtx = ctx->typeIdentifier();
    string typeName = toLowerCase(idCtx->IDENTIFIER()->getText());
    SymtabEntry *typeId = symtabStack->lookupLocal(typeName);

    PascalParser::TypeSpecificationContext *typespecCtx = ctx->typeSpecification();

    if (typeId == nullptr) {
        PascalParser::TypeSpecificationContext *typeCtx = ctx->typeSpecification();
        visit(typeCtx);

        typeId = symtabStack->enterLocal(typeName, TYPE);
        typeId->setType(typeCtx->type);
        typeCtx->type->setIdentifier(typeId);
    } else {
        error.flag(REDECLARED_IDENTIFIER, ctx);
    }

    idCtx->entry = typeId;
    idCtx->type  = typespecCtx->type;

    typeId->appendLineNumber(ctx->getStart()->getLine());
    return nullptr;
}

Object Semantics::visitSimpleTypespec(PascalParser::SimpleTypespecContext *ctx) {
    visit(ctx->simpleType());
    ctx->type = ctx->simpleType()->type;

    return nullptr;
}

Object Semantics::visitTypeIdentifierTypespec(PascalParser::TypeIdentifierTypespecContext *ctx) {
    visit(ctx->typeIdentifier());
    ctx->type = ctx->typeIdentifier()->type;

    return nullptr;
}

Object Semantics::visitTypeIdentifier(PascalParser::TypeIdentifierContext *ctx) {
    string typeName = toLowerCase(ctx->IDENTIFIER()->getText());
    SymtabEntry *typeId = symtabStack->lookup(typeName);

    if (typeId != nullptr) {
        if (typeId->getKind() != TYPE) {
            error.flag(INVALID_TYPE, ctx);
            ctx->type = Predefined::integerType;
        } else {
            ctx->type = typeId->getType();
        }

        typeId->appendLineNumber(ctx->start->getLine());
    } else {
        error.flag(UNDECLARED_IDENTIFIER, ctx);
        ctx->type = Predefined::integerType;
    }

    ctx->entry = typeId;
    return nullptr;
}

Object Semantics::visitArrayTypespec(PascalParser::ArrayTypespecContext *ctx) {
    Typespec *arrayType = new Typespec(ARRAY);
    PascalParser::ArrayTypeContext *arrayCtx = ctx->arrayType();
    PascalParser::ArrayDimensionListContext *listCtx = arrayCtx->arrayDimensionList();
    ctx->type = arrayType;
    int count = listCtx->simpleType().size();
    for (int i = 0; i < count; i++) {
        PascalParser::SimpleTypeContext *simpleCtx = listCtx->simpleType()[i];
        visit(simpleCtx);
        arrayType->setArrayIndexType(simpleCtx->type);
        arrayType->setArrayElementCount(0);

        if (i < count-1) {
            Typespec *elmtType = new Typespec(ARRAY);
            arrayType->setArrayElementType(elmtType);
            arrayType = elmtType;
        }
    }

    visit(arrayCtx->typeSpecification());
    Typespec *elmtType = arrayCtx->typeSpecification()->type;
    arrayType->setArrayElementType(elmtType);

    return nullptr;
}

Object Semantics::visitVariableDeclarations(PascalParser::VariableDeclarationsContext *ctx) {
    PascalParser::TypeSpecificationContext *typeCtx = ctx->typeSpecification();
    visit(typeCtx);

    PascalParser::VariableIdentifierListContext *listCtx = ctx->variableIdentifierList();

    for (PascalParser::VariableIdentifierContext *idCtx : listCtx->variableIdentifier()) {
        int lineNumber = idCtx->getStart()->getLine();
        string variableName = toLowerCase(idCtx->IDENTIFIER()->getText());
        SymtabEntry *variableId = symtabStack->lookupLocal(variableName);

        if (variableId == nullptr) {
            variableId = symtabStack->enterLocal(variableName, VARIABLE);
            variableId->setType(typeCtx->type);

            Symtab *symtab = variableId->getSymtab();
            if (symtab->getNestingLevel() > 1) {
                variableId->setSlotNumber(symtab->nextSlotNumber());
            }

            idCtx->entry = variableId;
        } else {
            error.flag(REDECLARED_IDENTIFIER, ctx);
        }

        variableId->appendLineNumber(lineNumber);
    }

    return nullptr;
}

Object Semantics::visitRoutineDefinition(PascalParser::RoutineDefinitionContext *ctx) {
    PascalParser::FunctionHeadContext  *funcCtx = ctx->functionHead();
    PascalParser::RoutineIdentifierContext *idCtx = nullptr;
    PascalParser::ParametersContext *parameters = nullptr;
    bool functionDefinition = funcCtx != nullptr;
    Typespec *returnType = nullptr;
    string routineName;

    idCtx = funcCtx->routineIdentifier();
    parameters = funcCtx->parameters();

    routineName = toLowerCase(idCtx->IDENTIFIER()->getText());
    SymtabEntry *routineId = symtabStack->lookupLocal(routineName);

    if (routineId != nullptr) {
        error.flag(REDECLARED_IDENTIFIER, ctx->getStart()->getLine(), routineName);
        return nullptr;
    }

    routineId = symtabStack->enterLocal(routineName, FUNCTION);
    routineId->setRoutineCode(DECLARED);
    idCtx->entry = routineId;

    SymtabEntry *parentId = symtabStack->getLocalSymtab()->getOwner();
    parentId->appendSubroutine(routineId);

    routineId->setRoutineSymtab(symtabStack->push());
    idCtx->entry = routineId;

    Symtab *symtab = symtabStack->getLocalSymtab();
    symtab->setOwner(routineId);

    if (parameters != nullptr) {
        vector<SymtabEntry *> *parameterIds = visit(parameters->parameterDeclarationsList()).as<vector<SymtabEntry *>*>();
        routineId->setRoutineParameters(parameterIds);

        for (SymtabEntry *parmId : *parameterIds) {
            parmId->setSlotNumber(symtab->nextSlotNumber());
        }
    }

    if (functionDefinition) {
        PascalParser::TypeIdentifierContext *typeIdCtx = funcCtx->typeIdentifier();
        visit(typeIdCtx);
        returnType = typeIdCtx->type;

        if (returnType->getForm() != SCALAR) {
            error.flag(INVALID_RETURN_TYPE, typeIdCtx);
            returnType = Predefined::integerType;
        }

        routineId->setType(returnType);
        idCtx->type = returnType;
    } else {
        idCtx->type = nullptr;
    }

    visit(ctx->block()->declarations());

    if (functionDefinition) {
        SymtabEntry *assocVarId = symtabStack->enterLocal(routineName, VARIABLE);
        assocVarId->setSlotNumber(symtab->nextSlotNumber());
        assocVarId->setType(returnType);
    }

    visit(ctx->block()->compoundStatement());
    routineId->setExecutable(ctx->block()->compoundStatement());

    symtabStack->pop();
    return nullptr;
}

Object Semantics::visitParameterDeclarationsList(PascalParser::ParameterDeclarationsListContext *ctx) {
    vector<SymtabEntry *> *parameterList = new vector<SymtabEntry *>();

    for (PascalParser::ParameterDeclarationsContext *dclCtx : ctx->parameterDeclarations()) {
        vector<SymtabEntry *> parameterSublist = visit(dclCtx).as<vector<SymtabEntry *>>();
        for (SymtabEntry *id : parameterSublist) parameterList->push_back(id);
    }

    return parameterList;
}

Object Semantics::visitParameterDeclarations(PascalParser::ParameterDeclarationsContext *ctx) {
    Kind kind = ctx->VAR() != nullptr ? REFERENCE_PARAMETER : VALUE_PARAMETER;
    PascalParser::TypeIdentifierContext *typeCtx = ctx->typeIdentifier();

    visit(typeCtx);
    Typespec *parmType = typeCtx->type;

    vector<SymtabEntry *> parameterSublist;

    PascalParser::ParameterIdentifierListContext *listCtx = ctx->parameterIdentifierList();
    for (PascalParser::ParameterIdentifierContext *idCtx : listCtx->parameterIdentifier()) {
        int lineNumber = idCtx->getStart()->getLine();
        string parmName = toLowerCase(idCtx->IDENTIFIER()->getText());
        SymtabEntry *parmId = symtabStack->lookupLocal(parmName);

        if (parmId == nullptr) {
            parmId = symtabStack->enterLocal(parmName, kind);
            parmId->setType(parmType);
        } else {
            error.flag(REDECLARED_IDENTIFIER, idCtx);
        }

        idCtx->entry = parmId;
        idCtx->type  = parmType;

        parameterSublist.push_back(parmId);
        parmId->appendLineNumber(lineNumber);
    }

    return parameterSublist;
}

Object Semantics::visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) {
    PascalParser::LhsContext *lhsCtx = ctx->lhs();
    PascalParser::RhsContext *rhsCtx = ctx->rhs();

    visitChildren(ctx);

    Typespec *lhsType = lhsCtx->type;
    Typespec *rhsType = rhsCtx->expression()->type;

    if (!TypeChecker::areAssignmentCompatible(lhsType, rhsType)) {
        error.flag(INCOMPATIBLE_ASSIGNMENT, ctx);
    }

    return nullptr;
}

Object Semantics::visitLhs(PascalParser::LhsContext *ctx) {
    PascalParser::VariableContext *varCtx = ctx->variable();
    visit(varCtx);
    ctx->type = varCtx->type;

    return nullptr;
}

Object Semantics::visitIfStatement(PascalParser::IfStatementContext *ctx) {
    PascalParser::ExpressionContext     *exprCtx  = ctx->expression();
    PascalParser::TrueStatementContext  *trueCtx  = ctx->trueStatement();
    PascalParser::FalseStatementContext *falseCtx = ctx->falseStatement();

    visit(exprCtx);
    Typespec *expr_type = exprCtx->type;
    
    if (!TypeChecker::isBoolean(expr_type)) {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }
    
    visit(trueCtx);
    if (falseCtx != nullptr) visit(falseCtx);

    return nullptr;
}

Object Semantics::visitCaseStatement(PascalParser::CaseStatementContext *ctx) {
    PascalParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    Typespec *exprType = exprCtx->type;
    Form exprTypeForm = exprType->getForm();

    if ((exprTypeForm != SCALAR)
        || (exprType == Predefined::realType)
        || (exprType == Predefined::stringType)) {
        error.flag(TYPE_MISMATCH, exprCtx);
        exprType = Predefined::integerType;
    }

    set<int> constants;
    PascalParser::CaseBranchListContext *branchListCtx = ctx->caseBranchList();

    for (PascalParser::CaseBranchContext *branchCtx : branchListCtx->caseBranch()) {
        PascalParser::CaseConstantListContext *constListCtx = branchCtx->caseConstantList();
        PascalParser::StatementContext *stmtCtx = branchCtx->statement();

        if (constListCtx != nullptr) {
            for (PascalParser::CaseConstantContext *caseConstCtx : constListCtx->caseConstant()) {
                PascalParser::ConstantContext *constCtx = caseConstCtx->constant();
                Object constValue = visit(constCtx);

                caseConstCtx->type  = constCtx->type;
                caseConstCtx->value = 0;

                if (constCtx->type != exprType) {
                    error.flag(TYPE_MISMATCH, constCtx);
                } else if ( (constCtx->type == Predefined::integerType)) {
                    caseConstCtx->value = constValue.as<int>();
                } else if (constCtx->type == Predefined::charType) {
                    caseConstCtx->value = constValue.as<char>();
                }

                if (constants.find(caseConstCtx->value) != constants.end()) {
                    error.flag(DUPLICATE_CASE_CONSTANT, constCtx);
                }
                else {
                    constants.insert(caseConstCtx->value);
                }
            }
        }
        if (stmtCtx != nullptr) visit(stmtCtx);
    }

    return nullptr;
}

Object Semantics::visitRepeatStatement(PascalParser::RepeatStatementContext *ctx) {
    PascalParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    Typespec *exprType = exprCtx->type;

    if (!TypeChecker::isBoolean(exprType)) {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }

    visit(ctx->statementList());
    return nullptr;
}

Object Semantics::visitWhileStatement(PascalParser::WhileStatementContext *ctx) {
    PascalParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    Typespec *exprType = exprCtx->type;

    if (!TypeChecker::isBoolean(exprType)) {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }

    visit(ctx->statement());
    return nullptr;
}

Object Semantics::visitForStatement(PascalParser::ForStatementContext *ctx) {
    PascalParser::VariableContext *varCtx = ctx->variable();
    visit(varCtx);

    string controlName = toLowerCase(varCtx->variableIdentifier()->getText());
    Typespec *controlType = Predefined::integerType;

    if (varCtx->entry != nullptr) {
        controlType = varCtx->type;
        if (   (controlType->getForm() != SCALAR )
            || (controlType == Predefined::realType)
            || (controlType == Predefined::stringType)) 
        {
            error.flag(INVALID_CONTROL_VARIABLE, varCtx);
        }
    } else {
        error.flag(UNDECLARED_IDENTIFIER, ctx->getStart()->getLine(), controlName);
    }

    PascalParser::ExpressionContext *startCtx = ctx->expression()[0];
    PascalParser::ExpressionContext *endCtx   = ctx->expression()[1];

    visit(startCtx);
    visit(endCtx);

    if (startCtx->type != controlType)  error.flag(TYPE_MISMATCH, startCtx);
    if (startCtx->type != endCtx->type) error.flag(TYPE_MISMATCH, endCtx);

    visit(ctx->statement());
    return nullptr;
}

Object Semantics::visitFunctionCallFactor(PascalParser::FunctionCallFactorContext *ctx) {
    PascalParser::FunctionCallContext *callCtx = ctx->functionCall();
    PascalParser::FunctionNameContext *nameCtx = callCtx->functionName();
    PascalParser::ArgumentListContext *listCtx = callCtx->argumentList();
    string name = toLowerCase(callCtx->functionName()->getText());
    SymtabEntry *functionId = symtabStack->lookup(name);
    bool badName = false;

    ctx->type = Predefined::integerType;

    if (functionId == nullptr) {
        error.flag(UNDECLARED_IDENTIFIER, nameCtx);
        badName = true;
    } else if (functionId->getKind() != FUNCTION) {
        error.flag(NAME_MUST_BE_FUNCTION, nameCtx);
        badName = true;
    }

    if (badName) {
        for (PascalParser::ArgumentContext *exprCtx : listCtx->argument()) {
            visit(exprCtx);
        }
    } else {
        vector<SymtabEntry *> *parms = functionId->getRoutineParameters();
        checkCallArguments(listCtx, parms);
        ctx->type = functionId->getType();
    }

    nameCtx->entry = functionId;
    nameCtx->type  = ctx->type;

    return nullptr;
}

void Semantics::checkCallArguments(PascalParser::ArgumentListContext *listCtx, vector<SymtabEntry *> *parms) {
    int parmsCount = parms->size();
    int argsCount = listCtx != nullptr ? listCtx->argument().size() : 0;

    if (parmsCount != argsCount) {
        error.flag(ARGUMENT_COUNT_MISMATCH, listCtx);
        return;
    }

    for (int i = 0; i < parmsCount; i++) {
        PascalParser::ArgumentContext *argCtx = listCtx->argument()[i];
        PascalParser::ExpressionContext *exprCtx = argCtx->expression();
        visit(exprCtx);

        SymtabEntry *parmId = (*parms)[i];
        Typespec *parmType = parmId->getType();
        Typespec *argType  = exprCtx->type;

        if (parmId->getKind() == REFERENCE_PARAMETER) {
            if (expressionIsVariable(exprCtx)) {
                if (parmType != argType) {
                    error.flag(TYPE_MISMATCH, exprCtx);
                }
            } else {
                error.flag(ARGUMENT_MUST_BE_VARIABLE, exprCtx);
            }
        } else if (!TypeChecker::areAssignmentCompatible(parmType, argType)) {
            error.flag(TYPE_MISMATCH, exprCtx);
        }
    }
}

bool Semantics::expressionIsVariable(PascalParser::ExpressionContext *exprCtx) {
    if (exprCtx->simpleExpression().size() == 1) {
        PascalParser::SimpleExpressionContext *simpleCtx = exprCtx->simpleExpression()[0];
        if (simpleCtx->term().size() == 1) {
            PascalParser::TermContext *termCtx = simpleCtx->term()[0];

            if (termCtx->factor().size() == 1) {
                return dynamic_cast<PascalParser::VariableFactorContext *>(termCtx->factor()[0]) != nullptr;
            }
        }
    }

    return false;
}

Object Semantics::visitExpression(PascalParser::ExpressionContext *ctx) {
    PascalParser::SimpleExpressionContext *simpleCtx1 = ctx->simpleExpression()[0];
    visit(simpleCtx1);

    Typespec *simpleType1 = simpleCtx1->type;
    ctx->type = simpleType1;

    PascalParser::RelOpContext *relopCtx = ctx->relOp();

    if (relopCtx != nullptr) {
        PascalParser::SimpleExpressionContext *simpleCtx2 = ctx->simpleExpression()[1];
        visit(simpleCtx2);

        Typespec *simpleType2 = simpleCtx2->type;
        if (!TypeChecker::areComparisonCompatible(simpleType1, simpleType2)) {
            error.flag(INCOMPATIBLE_COMPARISON, ctx);
        }

        ctx->type = Predefined::booleanType;
    }

    return nullptr;
}

Object Semantics::visitSimpleExpression(PascalParser::SimpleExpressionContext *ctx) {
    int count = ctx->term().size();
    PascalParser::SignContext *signCtx = ctx->sign();
    bool hasSign = signCtx != nullptr;
    PascalParser::TermContext *termCtx1 = ctx->term()[0];

    if (hasSign) {
        string sign = signCtx->getText();
        if ((sign== "+") && (sign == "-")) {
            error.flag(INVALID_SIGN, signCtx);
        }
    }

    visit(termCtx1);
    Typespec *termType1 = termCtx1->type;

    for (int i = 1; i < count; i++) {
        string op = toLowerCase(ctx->addOp()[i-1]->getText());
        PascalParser::TermContext *termCtx2 = ctx->term()[i];
        visit(termCtx2);
        Typespec *termType2 = termCtx2->type;

        if (op == "or") {
            if (!TypeChecker::isBoolean(termType1)){
                error.flag(TYPE_MUST_BE_BOOLEAN, termCtx1);
            }
            if (!TypeChecker::isBoolean(termType2)){
                error.flag(TYPE_MUST_BE_BOOLEAN, termCtx2);
            }
            if (hasSign){
                error.flag(INVALID_SIGN, signCtx);
            }

            termType2 = Predefined::booleanType;
        } else if (op == "+"){
            if (TypeChecker::areBothInteger(termType1, termType2)) {
                termType2 = Predefined::integerType;
            } else if (TypeChecker::isAtLeastOneReal(termType1, termType2)) {
                termType2 = Predefined::realType;
            } else if (TypeChecker::areBothString(termType1, termType2)) {
                if (hasSign) error.flag(INVALID_SIGN, signCtx);
                termType2 = Predefined::stringType;
            } else { 
                if (!TypeChecker::isIntegerOrReal(termType1)) {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx1);
                    termType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(termType2)) {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx2);
                    termType2 = Predefined::integerType;
                }
            }
        } else {
            if (TypeChecker::areBothInteger(termType1, termType2)) {
                termType2 = Predefined::integerType;
            } else if (TypeChecker::isAtLeastOneReal(termType1, termType2)) {
                termType2 = Predefined::realType;
            } else {
                if (!TypeChecker::isIntegerOrReal(termType1)) {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx1);
                    termType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(termType2)) {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx2);
                    termType2 = Predefined::integerType;
                }
            }
        }

        termType1 = termType2;
    }

    ctx->type = termType1;
    return nullptr;
}

Object Semantics::visitTerm(PascalParser::TermContext *ctx) {
    int count = ctx->factor().size();
    PascalParser::FactorContext *factorCtx1 = ctx->factor()[0];

    visit(factorCtx1);
    Typespec *factorType1 = factorCtx1->type;

    for (int i = 1; i < count; i++) {
        string op = toLowerCase(ctx->mulOp()[i-1]->getText());
        PascalParser::FactorContext *factorCtx2 = ctx->factor()[i];
        visit(factorCtx2);
        Typespec *factorType2 = factorCtx2->type;

        if (op == "*") {
            if (TypeChecker::areBothInteger(factorType1, factorType2)) {
                factorType2 = Predefined::integerType;
            } else if (TypeChecker::isAtLeastOneReal(factorType1, factorType2)) {
                factorType2 = Predefined::realType;
            } else {
                if (!TypeChecker::isIntegerOrReal(factorType1)) {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx1);
                    factorType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(factorType2)) {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx2);
                    factorType2 = Predefined::integerType;
                }
            }
        } else if (op == "/"){
            if (   TypeChecker::areBothInteger(factorType1, factorType2)
                || TypeChecker::isAtLeastOneReal(factorType1, factorType2)) {
                factorType2 = Predefined::realType;
            } else {
                if (!TypeChecker::isIntegerOrReal(factorType1)) {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx1);
                    factorType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(factorType2)) {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx2);
                    factorType2 = Predefined::integerType;
                }
            }
        } else if ((op == "div") ||(op == "mod")) {
            if (!TypeChecker::isInteger(factorType1)) {
                error.flag(TYPE_MUST_BE_INTEGER, factorCtx1);
                factorType2 = Predefined::integerType;
            } 
            if (!TypeChecker::isInteger(factorType2)) {
                error.flag(TYPE_MUST_BE_INTEGER, factorCtx2);
                factorType2 = Predefined::integerType;
            }

            ctx->type = Predefined::integerType;
        } else if (op == "and") {
            if (!TypeChecker::isBoolean(factorType1)) {
                error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx1);
                factorType2 = Predefined::booleanType;
            }
            if (!TypeChecker::isBoolean(factorType2)) {
                error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx2);
                factorType2 = Predefined::booleanType;
            }
        }

        factorType1 = factorType2;
    }

    ctx->type = factorType1;
    return nullptr;
}

Object Semantics::visitVariableFactor(PascalParser::VariableFactorContext *ctx) {
    PascalParser::VariableContext *varCtx = ctx->variable();
    visit(varCtx);
    ctx->type = varCtx->type;

    return nullptr;
}

Object Semantics::visitVariable(PascalParser::VariableContext *ctx) {
    PascalParser::VariableIdentifierContext *varIdCtx = ctx->variableIdentifier();

    visit(varIdCtx);
    ctx->entry = varIdCtx->entry;
    ctx->type  = variableDatatype(ctx, varIdCtx->type);

    return nullptr;
}

Object Semantics::visitVariableIdentifier(PascalParser::VariableIdentifierContext *ctx) {
    string variableName = toLowerCase(ctx->IDENTIFIER()->getText());
    SymtabEntry *variableId = symtabStack->lookup(variableName);

    if (variableId != nullptr) {
        int lineNumber = ctx->getStart()->getLine();
        ctx->type = variableId->getType();
        ctx->entry = variableId;
        variableId->appendLineNumber(lineNumber);

        Kind kind = variableId->getKind();
        switch (kind) {
            case TYPE:
            case PROGRAM:
            case PROGRAM_PARAMETER:
            case UNDEFINED:
                error.flag(INVALID_VARIABLE, ctx);
                break;

            default: break;
        }
    } else {
        error.flag(UNDECLARED_IDENTIFIER, ctx);
        ctx->type = Predefined::integerType;
    }

    return nullptr;
}

Typespec *Semantics::variableDatatype(PascalParser::VariableContext *varCtx, Typespec *varType) {
    Typespec *type = varType;

    for (PascalParser::ModifierContext *modCtx : varCtx->modifier()) {
        if (modCtx->indexList() != nullptr) {
            PascalParser::IndexListContext *indexListCtx = modCtx->indexList();

            for (PascalParser::IndexContext *indexCtx : indexListCtx->index()) {
                if (type->getForm() == ARRAY) {
                    Typespec *indexType = type->getArrayIndexType();
                    PascalParser::ExpressionContext *exprCtx = indexCtx->expression();
                    visit(exprCtx);

                    if (indexType->baseType() != exprCtx->type->baseType()) {
                        error.flag(TYPE_MISMATCH, exprCtx);
                    }

                    type = type->getArrayElementType();
                } else {
                    error.flag(TOO_MANY_SUBSCRIPTS, indexCtx);
                }
            }
        } else {
            error.flag(INVALID_FIELD, modCtx);
        }
    }

    return type;
}

Object Semantics::visitNumberFactor(PascalParser::NumberFactorContext *ctx) {
    PascalParser::NumberContext          *numberCtx   = ctx->number();
    PascalParser::UnsignedNumberContext  *unsignedCtx = numberCtx->unsignedNumber();
    PascalParser::IntegerConstantContext *integerCtx  = unsignedCtx->integerConstant();

    ctx->type = (integerCtx != nullptr) ? Predefined::integerType : Predefined::realType;

    return nullptr;
}

Object Semantics::visitCharacterFactor(PascalParser::CharacterFactorContext *ctx) {
    ctx->type = Predefined::charType;
    return nullptr;
}

Object Semantics::visitStringFactor(PascalParser::StringFactorContext *ctx) {
    ctx->type = Predefined::stringType;
    return nullptr;
}

Object Semantics::visitNotFactor(PascalParser::NotFactorContext *ctx) {
    PascalParser::FactorContext *factorCtx = ctx->factor();
    visit(factorCtx);

    if (factorCtx->type != Predefined::booleanType) {
        error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx);
    }

    ctx->type = Predefined::booleanType;
    return nullptr;
}

Object Semantics::visitParenthesizedFactor(PascalParser::ParenthesizedFactorContext *ctx) {
    PascalParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    ctx->type = exprCtx->type;

    return nullptr;
}

}
