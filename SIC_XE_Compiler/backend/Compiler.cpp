#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"

namespace backend {
using namespace std;

Object Compiler::visitProgram(PascalParser::ProgramContext *ctx) {
    cout << "visitProgram" << endl << flush;
    createNewGenerators(code);
    programCode->emitProgram(ctx);
    return nullptr;
}

Object Compiler::visitRoutineDefinition(PascalParser::RoutineDefinitionContext *ctx) {
    cout << "visitRoutineDefinition" << endl << flush;
    createNewGenerators(programCode);
    programCode->emitRoutine(ctx);
    return nullptr;
}

Object Compiler::visitStatement(PascalParser::StatementContext *ctx) {
    cout << "visitStatement" << endl << flush;
    if ((ctx->compoundStatement() == nullptr) && (ctx->emptyStatement() == nullptr)) {
        expressionCode->emitComment(ctx);
    }

    return visitChildren(ctx);
}

Object Compiler::visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) {
    cout << "visitAssignmentStatement" << endl << flush;
    expressionCode->emitAssignment(ctx);
    return nullptr;
}

Object Compiler::visitExpression(PascalParser::ExpressionContext *ctx) {
    cout << "visitExpression" << endl << flush;
    expressionCode->emitExpression(ctx);
    return nullptr;
}

Object Compiler::visitVariable(PascalParser::VariableContext *ctx) {
    cout << "visitVariable" << endl << flush;
    expressionCode->emitLoadVariable(ctx);
    return nullptr;
}

Object Compiler::visitVariableFactor(PascalParser::VariableFactorContext *ctx) {
    cout << "visitVariableFactor" << endl << flush;
    expressionCode->emitLoadVariable(ctx->variable());
    return nullptr;
}

Object Compiler::visitNumberFactor(PascalParser::NumberFactorContext *ctx) {
    cout << "visitNumberFactor" << endl << flush;
   if (ctx->type == Predefined::integerType) {
        expressionCode->emitLoadIntegerConstant(ctx->number());
    } else {
        expressionCode->emitLoadRealConstant(ctx->number());
    }

    return nullptr;
}

Object Compiler::visitCharacterFactor(PascalParser::CharacterFactorContext *ctx) {
    cout << "visitCharacterFactor" << endl << flush;
    char ch = ctx->getText()[1];
    expressionCode->emitLoadConstant(ch, 1, 0);

    return nullptr;
}

Object Compiler::visitFunctionCallFactor(PascalParser::FunctionCallFactorContext *ctx) {
    cout << "visitFunctionCallFactor" << endl << flush;
    expressionCode->emitFunctionCall(ctx->functionCall());
    return nullptr;
}

Object Compiler::visitNotFactor(PascalParser::NotFactorContext *ctx) {
    cout << "visitNotFactor" << endl << flush;
    expressionCode->emitNotFactor(ctx);
    return nullptr;
}

Object Compiler::visitParenthesizedFactor(PascalParser::ParenthesizedFactorContext *ctx) {
    cout << "visitParenthesizedFactor" << endl << flush;
    return visit(ctx->expression());
}

}
