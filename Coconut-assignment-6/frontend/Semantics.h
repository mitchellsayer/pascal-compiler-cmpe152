#ifndef SEMANTICS_H_
#define SEMANTICS_H_

#include <map>
#include <fstream>
#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/util/BackendMode.h"
#include "ErrorHandlers.h"

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class Semantics : public PascalBaseVisitor {
private:
    SymtabStack *symtabStack;
    SymtabEntry *programId;
    SemanticErrorHandler error;

    map<string, Typespec *> *typeTable;

    bool expressionIsVariable(PascalParser::ExpressionContext *exprCtx);

    void checkCallArguments(PascalParser::ArgumentListContext *listCtx, vector<SymtabEntry *> *parms);

    Typespec *variableDatatype(PascalParser::VariableContext *varCtx, Typespec *varType);

public:
    Semantics() {
        symtabStack = new SymtabStack();
        Predefined::initialize(symtabStack);

        typeTable = new map<string, Typespec *>();
        (*typeTable)["integer"] = Predefined::integerType;
        (*typeTable)["real"]    = Predefined::realType;
        (*typeTable)["boolean"] = Predefined::booleanType;
        (*typeTable)["char"]    = Predefined::charType;
        (*typeTable)["string"]  = Predefined::stringType;
    }

    SymtabEntry *getProgramId() { return programId; }

    int getErrorCount() const { return error.getCount(); }

    static Object defaultValue(Typespec *type);

    Object visitProgram(PascalParser::ProgramContext *ctx) override;
    Object visitProgramHeader(PascalParser::ProgramHeaderContext *ctx) override;
    Object visitVariableDeclarations(PascalParser::VariableDeclarationsContext *ctx) override;
    Object visitParameterDeclarations(PascalParser::ParameterDeclarationsContext *ctx) override;
    Object visitParameterDeclarationsList(PascalParser::ParameterDeclarationsListContext *ctx) override;

    Object visitConstant(PascalParser::ConstantContext *ctx) override;
    Object visitConstantDefinition(PascalParser::ConstantDefinitionContext *ctx) override;
    Object visitArrayTypespec(PascalParser::ArrayTypespecContext *ctx) override;

    Object visitLhs(PascalParser::LhsContext *ctx) override;
    Object visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) override;
    
    Object visitTypeDefinition(PascalParser::TypeDefinitionContext *ctx) override;
    Object visitTypeIdentifier(PascalParser::TypeIdentifierContext *ctx) override;
    Object visitSimpleTypespec(PascalParser::SimpleTypespecContext *ctx) override;
    Object visitTypeIdentifierTypespec(PascalParser::TypeIdentifierTypespecContext *ctx) override;
    Object visitVariable(PascalParser::VariableContext *ctx) override;
    Object visitVariableIdentifier(PascalParser::VariableIdentifierContext *ctx) override;

    Object visitIfStatement(PascalParser::IfStatementContext *ctx) override;
    Object visitCaseStatement(PascalParser::CaseStatementContext *ctx) override;
    Object visitRepeatStatement(PascalParser::RepeatStatementContext *ctx) override;
    Object visitWhileStatement(PascalParser::WhileStatementContext *ctx) override;
    Object visitForStatement(PascalParser::ForStatementContext *ctx) override;
    
    Object visitRoutineDefinition(PascalParser::RoutineDefinitionContext *ctx) override;
    Object visitExpression(PascalParser::ExpressionContext *ctx) override;
    Object visitSimpleExpression(PascalParser::SimpleExpressionContext *ctx) override;
    Object visitTerm(PascalParser::TermContext *ctx) override;

    Object visitFunctionCallFactor(PascalParser::FunctionCallFactorContext *ctx) override;
    Object visitVariableFactor(PascalParser::VariableFactorContext *ctx) override;
    Object visitNumberFactor(PascalParser::NumberFactorContext *ctx) override;
    Object visitCharacterFactor(PascalParser::CharacterFactorContext *ctx) override;
    Object visitStringFactor(PascalParser::StringFactorContext *ctx) override;
    Object visitNotFactor(PascalParser::NotFactorContext *ctx) override;
    Object visitParenthesizedFactor(PascalParser::ParenthesizedFactorContext *ctx) override;
};

}

#endif /* SEMANTICS_H_ */
