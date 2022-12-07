#ifndef PROGRAMGENERATOR_H_
#define PROGRAMGENERATOR_H_

#include "CodeGenerator.h"

namespace backend {

class ProgramGenerator : public CodeGenerator {
private:
    SymtabEntry *programId;  // symbol table entry of the program name
    int programLocalsCount;  // count of program local variables

public:
    ProgramGenerator(CodeGenerator *parent, Compiler *compiler): CodeGenerator(parent, compiler), programId(nullptr), programLocalsCount(0) {}

    void emitProgram(PascalParser::ProgramContext *ctx);

    void emitRoutine(PascalParser::RoutineDefinitionContext *ctx);

private:
    void emitProgramVariables();

    void emitSubroutines(PascalParser::RoutinesPartContext *ctx);

    void emitMainMethod(PascalParser::ProgramContext *ctx);

    void emitMainPrologue(SymtabEntry *programId);

    void emitMainEpilogue();

    void emitRoutineHeader(SymtabEntry *routineId);

    int emitRoutineLocals(SymtabEntry *routineId);

    void emitRoutineReturn(SymtabEntry *routineId);

    void emitRoutineEpilogue();
};

}

#endif
