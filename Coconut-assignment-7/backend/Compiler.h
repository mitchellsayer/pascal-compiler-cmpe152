#ifndef COMPILER_H_
#define COMPILER_H_

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"
#include "ProgramGenerator.h"
#include "StatementGenerator.h"
#include "ExpressionGenerator.h"

namespace backend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class CodeGenerator;

class Compiler : public PascalBaseVisitor {
private:
    SymtabEntry *programId;  // symbol table entry of the program name
    string programName;      // the program name

    CodeGenerator       *code;            // base code generator
    ProgramGenerator    *programCode;     // program code generator
    StatementGenerator  *statementCode;   // statement code generator
    ExpressionGenerator *expressionCode;  // expression code generator

public:
    Compiler(SymtabEntry *programId) : 
            programId(programId),
            code(new CodeGenerator(programName, "j", this)), 
            programCode(nullptr),
            statementCode(nullptr), 
            expressionCode(nullptr),
            programName(programId->getName()) 
    {
        std::cout << "ProgramName: " << programId->getName() << std::endl;
    }
                 
    Compiler(Compiler *parent): 
        programId(parent->programId), 
        programName(parent->programName),
        code(parent->code),
        programCode(parent->programCode),
        statementCode(nullptr),
        expressionCode(nullptr) 
        {}

    // string getObjectFileName() { return code->getObjectFileName(); }

    Object visitProgram(PascalParser::ProgramContext *ctx) override;
    Object visitRoutineDefinition(PascalParser::RoutineDefinitionContext *ctx) override;
    Object visitStatement(PascalParser::StatementContext *ctx) override;
    Object visitAssignmentStatement(PascalParser::AssignmentStatementContext *ctx) override;
    Object visitIfStatement(PascalParser::IfStatementContext *ctx) override;
    Object visitCaseStatement(PascalParser::CaseStatementContext *ctx) override;
    Object visitRepeatStatement(PascalParser::RepeatStatementContext *ctx) override;
    Object visitWhileStatement(PascalParser::WhileStatementContext *ctx) override;
    Object visitForStatement(PascalParser::ForStatementContext *ctx) override;
    Object visitExpression(PascalParser::ExpressionContext *ctx) override;
    Object visitVariableFactor(PascalParser::VariableFactorContext *ctx) override;
    Object visitVariable(PascalParser::VariableContext *ctx) override;
    Object visitNumberFactor(PascalParser::NumberFactorContext *ctx) override;
    Object visitCharacterFactor(PascalParser::CharacterFactorContext *ctx) override;
    Object visitStringFactor(PascalParser::StringFactorContext *ctx) override;
    Object visitFunctionCallFactor(PascalParser::FunctionCallFactorContext *context) override;
    Object visitNotFactor(PascalParser::NotFactorContext *ctx) override;
    Object visitParenthesizedFactor(PascalParser::ParenthesizedFactorContext *ctx) override;
    Object visitWriteStatement(PascalParser::WriteStatementContext *ctx) override;
    Object visitWritelnStatement(PascalParser::WritelnStatementContext *ctx) override;
    Object visitReadStatement(PascalParser::ReadStatementContext *ctx) override;
    Object visitReadlnStatement(PascalParser::ReadlnStatementContext *ctx) override;

private:
    void createNewGenerators(CodeGenerator *parentGenerator) {
        programCode    = new ProgramGenerator(parentGenerator, this);
        statementCode  = new StatementGenerator(programCode, this);
        expressionCode = new ExpressionGenerator(programCode, this);
    }
};

}

#endif /* COMPILER_H_ */
