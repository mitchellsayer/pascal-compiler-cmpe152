#ifndef STATEMENTGENERATOR_H_
#define STATEMENTGENERATOR_H_

#include <vector>
#include <map>

#include "CodeGenerator.h"

namespace backend {

using namespace std;

class StatementGenerator : public CodeGenerator {
public:
    StatementGenerator(CodeGenerator *parent, Compiler *compiler) : CodeGenerator(parent, compiler) {}

    void emitAssignment(PascalParser::AssignmentStatementContext *ctx);

    void emitIf(PascalParser::IfStatementContext *ctx);

    void emitCase(PascalParser::CaseStatementContext *ctx);

    void emitRepeat(PascalParser::RepeatStatementContext *ctx);

    void emitWhile(PascalParser::WhileStatementContext *ctx);

    void emitFor(PascalParser::ForStatementContext *ctx);

    void emitFunctionCall(PascalParser::FunctionCallContext *ctx);

    void emitWrite(PascalParser::WriteStatementContext *ctx);

    void emitWriteln(PascalParser::WritelnStatementContext *ctx);

    void emitRead(PascalParser::ReadStatementContext *ctx);

    void emitReadln(PascalParser::ReadlnStatementContext *ctx);

private:
    map<int, Label *> *createCaseMap(PascalParser::CaseBranchListContext *branchListCtx, vector<Label *>& branchLabels);

    void emitLookupSwitch(map<int, Label *> *labelMap, vector<Label *>& branchLabels);

    void emitBranchStatements(PascalParser::CaseBranchListContext *branchListCtx, vector<Label *>& branchLabels);

    void emitCall(SymtabEntry *routineId, PascalParser::ArgumentListContext *argListCtx);

    void emitWrite(PascalParser::WriteArgumentsContext *argsCtx, bool needLF);

    int createWriteFormat(PascalParser::WriteArgumentsContext *argsCtx, string& format, bool needLF);

    void emitArgumentsArray(PascalParser::WriteArgumentsContext *argsCtx,int exprCount);

    void emitRead(PascalParser::ReadArgumentsContext *argsCtx, bool needSkip);
};

}

#endif /* STATEMENTGENERATOR_H_ */
