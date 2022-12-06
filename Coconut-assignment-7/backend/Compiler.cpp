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
//    if (   (ctx->compoundStatement() == nullptr)
//        && (ctx->emptyStatement() == nullptr)) {
    //     statementCode->emitComment(ctx);
    // }

    return visitChildren(ctx);
}

Object Compiler::visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) {
    cout << "visitAssignmentStatement" << endl << flush;
    statementCode->emitAssignment(ctx);
    return nullptr;
}

Object Compiler::visitIfStatement(PascalParser::IfStatementContext *ctx) {
    cout << "visitIfStatement" << endl << flush;
    statementCode->emitIf(ctx);
    return nullptr;
}

Object Compiler::visitCaseStatement(PascalParser::CaseStatementContext *ctx) {
    cout << "visitCaseStatement" << endl << flush;
    statementCode->emitCase(ctx);
    return nullptr;
}

Object Compiler::visitRepeatStatement(PascalParser::RepeatStatementContext *ctx) {
    cout << "visitRepeatStatement" << endl << flush;
    statementCode->emitRepeat(ctx);
    return nullptr;
}

Object Compiler::visitWhileStatement(PascalParser::WhileStatementContext *ctx) {
    cout << "visitWhileStatement" << endl << flush;
    statementCode->emitWhile(ctx);
    return nullptr;
}

Object Compiler::visitForStatement(PascalParser::ForStatementContext *ctx) {
    cout << "visitForStatement" << endl << flush;
    statementCode->emitFor(ctx);
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
    expressionCode->emitLoadValue(ctx->variable());
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
    // char ch = ctx->getText()[1];
    // expressionCode->emitLoadConstant(ch);

    return nullptr;
}

Object Compiler::visitStringFactor(PascalParser::StringFactorContext *ctx) {
    cout << "visitStringFactor" << endl << flush;
    // string jasminString = convertString(ctx->getText(), true);
    // expressionCode->emitLoadConstant(jasminString);

    return nullptr;
}

Object Compiler::visitFunctionCallFactor(PascalParser::FunctionCallFactorContext *ctx) {
    cout << "visitFunctionCallFactor" << endl << flush;
    statementCode->emitFunctionCall(ctx->functionCall());
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

Object Compiler::visitWriteStatement(PascalParser::WriteStatementContext *ctx) {
    cout << "visitWriteStatement" << endl << flush;
    statementCode->emitWrite(ctx);
    return nullptr;
}

Object Compiler::visitWritelnStatement(PascalParser::WritelnStatementContext *ctx) {
    cout << "visitWritelnStatement" << endl << flush;
    statementCode->emitWriteln(ctx);
    return nullptr;
}

Object Compiler::visitReadStatement(PascalParser::ReadStatementContext *ctx) {
    cout << "visitReadStatement" << endl << flush;
    statementCode->emitRead(ctx);
    return nullptr;
}

Object Compiler::visitReadlnStatement(PascalParser::ReadlnStatementContext *ctx) {
    cout << "visitReadlnStatement" << endl << flush;
    statementCode->emitReadln(ctx);
    return nullptr;
}

}
