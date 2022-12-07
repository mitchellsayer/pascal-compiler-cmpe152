#ifndef EXPRESSIONGENERATOR_H_
#define EXPRESSIONGENERATOR_H_

#include "CodeGenerator.h"

namespace backend {

class ExpressionGenerator : public CodeGenerator
{
public:
    ExpressionGenerator(CodeGenerator *parent, Compiler *compiler) : CodeGenerator(parent, compiler) {}

    void emitExpression(PascalParser::ExpressionContext *ctx);

    void emitSimpleExpression(PascalParser::SimpleExpressionContext *ctx);

    void emitTerm(PascalParser::TermContext *ctx);

    void emitNotFactor(PascalParser::NotFactorContext *ctx);

    void emitLoadValue(PascalParser::VariableContext *varCtx);

    Typespec *emitLoadVariable(PascalParser::VariableContext *varCtx);

    void emitLoadIntegerConstant(PascalParser::NumberContext *intCtx);

    void emitLoadRealConstant(PascalParser::NumberContext *realCtx);

    void emitAssignment(PascalParser::AssignmentStatementContext *ctx);

    void emitFunctionCall(PascalParser::FunctionCallContext *ctx);
};

}

#endif /* EXPRESSIONGENERATOR_H_ */
