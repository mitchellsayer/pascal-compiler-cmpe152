#ifndef PROGRAMGENERATOR_H_
#define PROGRAMGENERATOR_H_

#include "CodeGenerator.h"

namespace backend {

class ProgramGenerator : public CodeGenerator
{
private:
    SymtabEntry *programId;  // symbol table entry of the program name
    int programLocalsCount;  // count of program local variables

public:
    ProgramGenerator(CodeGenerator *parent, Compiler *compiler)
        : CodeGenerator(parent, compiler),
          programId(nullptr), programLocalsCount(5) // 5 because _elapsed is long
    {
        // localStack = new LocalStack();
    }

    void emitProgram(PascalParser::ProgramContext *ctx);

    void emitRoutine(PascalParser::RoutineDefinitionContext *ctx);

private:
    void emitProgramVariables();

    void emitMemoryDeclarations();

    void emitInputScanner();

    void emitConstructor();

    void emitSubroutines(PascalParser::RoutinesPartContext *ctx);

    void emitMainMethod(PascalParser::ProgramContext *ctx);

    void emitMainPrologue(SymtabEntry *programId);

    void emitMainEpilogue();

    void emitRoutineHeader(SymtabEntry *routineId);

    /*
     * Emit directives for the local variables.
     * @param routineId the symbol table entry of the routine's name.
     */
    void emitRoutineLocals(SymtabEntry *routineId);

    void emitRoutineReturn(SymtabEntry *routineId);

    void emitRoutineEpilogue();
};

}

#endif
