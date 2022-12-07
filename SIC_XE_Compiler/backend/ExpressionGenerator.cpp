#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "CodeGenerator.h"
#include "ExpressionGenerator.h"
#include "Compiler.h"

namespace backend {

void ExpressionGenerator::emitExpression(PascalParser::ExpressionContext *ctx) {
    cout << "emitExpression" << endl << flush;
    PascalParser::SimpleExpressionContext *simpleCtx1 = ctx->simpleExpression()[0];
    PascalParser::RelOpContext *relOpCtx = ctx->relOp();
    Typespec *type1 = simpleCtx1->type;
    emitSimpleExpression(simpleCtx1);

    if (relOpCtx != nullptr) {
        string op = relOpCtx->getText();
        PascalParser::SimpleExpressionContext *simpleCtx2 = ctx->simpleExpression()[1];
        Typespec *type2 = simpleCtx2->type;

        bool intMod   = false;
        bool reMod      = false;
        bool charMod = false;

        if ((type1 == Predefined::integerType) && (type2 == Predefined::integerType)) {
            intMod = true;
        } else if ((type1 == Predefined::realType) || (type2 == Predefined::realType)) {
            reMod = true;
        } else if ((type1 == Predefined::charType) && (type2 == Predefined::charType)) {
            charMod = true;
        }

        emitSimpleExpression(simpleCtx2);
    }
}

void ExpressionGenerator::emitSimpleExpression(PascalParser::SimpleExpressionContext *ctx) {
    cout << "emitSimpleExpression" << endl << flush;
    int count = ctx->term().size();
    bool negate = (ctx->sign() != nullptr) && (ctx->sign()->getText() == "-");

    PascalParser::TermContext *termCtx1 = ctx->term()[0];
    Typespec *type1 = termCtx1->type;
    emitTerm(termCtx1);

    for (int i = 1; i < count; i++) {
        string op = toLowerCase(ctx->addOp()[i-1]->getText());
        PascalParser::TermContext *termCtx2 = ctx->term()[i];
        Typespec *type2 = termCtx2->type;

        bool integerMode = false;
        bool realMode    = false;
        bool booleanMode = false;

        if ((type1 == Predefined::integerType) && (type2 == Predefined::integerType)) {
            integerMode = true;
        } else if (   (type1 == Predefined::realType) || (type2 == Predefined::realType)) {
            realMode = true;
        } else if ((type1 == Predefined::booleanType) && (type2 == Predefined::booleanType)) {
            booleanMode = true;
        }

        if (integerMode) {
            emitTerm(termCtx2);
            if (op == "+") {
                emit(ADD, "stack,x");
            } else {
                emit(SUB, "stack,x");
            }
        } else if (realMode) {
            if (type1 == Predefined::integerType) emit(FLOAT);
            emitTerm(termCtx2);
            if (type2 == Predefined::integerType) emit(FLOAT);

            if (op == "+") emit(ADDF, "stack,x");
            else           emit(SUBF, "stack,x");
        } else if (booleanMode) {
            emitTerm(termCtx2);
        }
    }
}

void ExpressionGenerator::emitTerm(PascalParser::TermContext *ctx) {
    cout << "emitTerm" << endl << flush;
    int count = ctx->factor().size();

    PascalParser::FactorContext *factorCtx1 = ctx->factor()[0];
    Typespec *type1 = factorCtx1->type;
    compiler->visit(factorCtx1);

    for (int i = 1; i < count; i++) {
        string op = toLowerCase(ctx->mulOp()[i-1]->getText());
        PascalParser::FactorContext *factorCtx2 = ctx->factor()[i];
        Typespec *type2 = factorCtx2->type;

        bool integerMode = false;
        bool realMode    = false;

        if ((type1 == Predefined::integerType) && (type2 == Predefined::integerType)) {
            integerMode = true;
        } else if ((type1 == Predefined::realType) || (type2 == Predefined::realType)) {
            realMode = true;
        }

        if (integerMode) {
            compiler->visit(factorCtx2);
            if (op == "*") emit(MUL, "stack,x");
            if (op == "/") emit(DIV, "stack,x");
        } else if (realMode) {
            if (type1 == Predefined::integerType) emit(FLOAT);
            compiler->visit(factorCtx2);
            if (type2 == Predefined::integerType) emit(FLOAT);

            if (op == "*") emit(MULF, "stack,x");
            if (op == "/") emit(DIVF, "stack,x");
        } else {
            compiler->visit(factorCtx2);
            emit(AND, "stack,x");
        }

        emit(type2->getIdentifier()->getValue());
    }
}

void ExpressionGenerator::emitNotFactor(PascalParser::NotFactorContext *ctx) {
    cout << "emitNotFactor" << endl << flush;
    compiler->visit(ctx->factor());
}

Typespec *ExpressionGenerator::emitLoadVariable(PascalParser::VariableContext *varCtx) {
    cout << "emitLoadVariable" << endl << flush;
    SymtabEntry *variableId = varCtx->entry;
    Typespec *variableType = variableId->getType();
    int modifierCount = varCtx->modifier().size();

    if (modifierCount > 0){
        PascalParser::ModifierContext *lastModCtx = varCtx->modifier()[modifierCount - 1];

        if (lastModCtx->indexList() != nullptr) {
            // Array Element Access
        } else {
            CodeGenerator::emitLoadValue(variableId);
        }
    }

    return variableType;
}

void ExpressionGenerator::emitLoadIntegerConstant(PascalParser::NumberContext *intCtx) {
    cout << "emitLoadIntegerConstant" << endl << flush;
    int value = stoi(intCtx->getText());
    emitLoadConstant(value, 3, 3);
}

void ExpressionGenerator::emitLoadRealConstant(PascalParser::NumberContext *realCtx) {
    cout << "emitLoadRealConstant" << endl << flush;
    float value = stof(realCtx->getText());
    emitLoadConstant(value, 6, 3);
}

void ExpressionGenerator::emitAssignment(PascalParser::AssignmentStatementContext *ctx) {
    cout << "emitAssignment" << endl << flush;
    PascalParser::VariableContext *varCtx  = ctx->lhs()->variable();
    PascalParser::ExpressionContext *exprCtx = ctx->rhs()->expression();
    SymtabEntry *varId = varCtx->entry;
    Typespec *varType  = varCtx->type;
    Typespec *exprType = exprCtx->type;

    int modifierCount = varCtx->modifier().size();
    PascalParser::ModifierContext *lastModCtx = modifierCount == 0 ? nullptr : varCtx->modifier()[modifierCount - 1];

    if (modifierCount > 0) {
        lastModCtx = varCtx->modifier()[modifierCount - 1];
        compiler->visit(varCtx);
    }

    compiler->visit(exprCtx);

    if ((varType == Predefined::realType) && (exprType->baseType() == Predefined::integerType)) {
        emit(LDA, (int)varId->getValue());
        emit(FLOAT);
        emit(STF, varId->getName());
    }

    if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());
    else if (lastModCtx->field() != nullptr) {
        emitStoreValue(lastModCtx->field()->entry, lastModCtx->field()->type);
    } else {
        emitStoreValue(nullptr, varType);
    }
}

void ExpressionGenerator::emitFunctionCall(PascalParser::FunctionCallContext *ctx) {
    cout << "emitFunctionCall" << endl << flush;
    PascalParser::ArgumentListContext *argListCtx = ctx->argumentList();
    PascalParser::FunctionNameContext *nameCtx = ctx->functionName();

    SymtabEntry *procSymtab = ctx->functionName()->entry;
    vector<SymtabEntry *> *parmIds = procSymtab->getRoutineParameters();

    compiler->visit(ctx->functionName());

    emit(JSUB, nameCtx->getText());
}

}
