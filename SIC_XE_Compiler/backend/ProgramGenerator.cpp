#include <vector>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "Opcode.h"
#include "Compiler.h"
#include "ProgramGenerator.h"

namespace backend {

using namespace std;

void ProgramGenerator::emitProgram(PascalParser::ProgramContext *ctx) {
    cout << "emitProgram" << endl << flush;
    programId = ctx->programHeader()->programIdentifier()->entry;
    Symtab *programSymtab = programId->getRoutineSymtab();

    // localVariables = new LocalVariables(programLocalsCount);

    emit(programId->getName(), START, 1000);

    emitProgramVariables();
    emitSubroutines(ctx->block()->declarations()->routinesPart());

    emitMainMethod(ctx);
}

void ProgramGenerator::emitProgramVariables() {
    cout << "emitProgramVariables" << endl << flush;

    Symtab *symtab = programId->getRoutineSymtab();
    vector<SymtabEntry *> ids = symtab->sortedEntries();

    for (SymtabEntry *id : ids) {
        if (id->getKind() == VARIABLE) {
            emit(id->getName(), RESW, 1);
        } else if (id->getKind() == CONSTANT) {
            Object val = id->getValue();
            if (id->getType()->baseType() == Predefined::integerType) {
                emit(id->getName(), WORD, (int)val);
            } else if (id->getType()->baseType() == Predefined::realType) {
                emit(id->getName(), DWORD, (double)val);
            }
        }
    }
}

void ProgramGenerator::emitSubroutines(PascalParser::RoutinesPartContext *ctx) {
    cout << "emitSubroutines" << endl << flush;
    if (ctx != nullptr) {
        for (PascalParser::RoutineDefinitionContext *routineDefCtx : ctx->routineDefinition()) {
            compiler = new Compiler(compiler);
            compiler->visit(routineDefCtx);
        }
    }
}

void ProgramGenerator::emitMainMethod(PascalParser::ProgramContext *ctx) {
    cout << "emitMainMethod" << endl << flush;
    SymtabEntry *routineId = ctx->programHeader()->programIdentifier()->entry;
    Symtab *routineSymtab = routineId->getRoutineSymtab();

    int varStackSize = 3 * routineSymtab->getMaxSlotNumber();

    emitComment("");
    emitComment("ROUTINE: MAIN" );
    emitComment("");
    emitComment("Call initFrame");

    emitLabel("MAIN");
    emit(LDX, "stackindex");
    emit(STL, "stack, x");
    emit(LDA, varStackSize);
    emit(LDB, routineSymtab->getNestingLevel());
    emit(JSUB, "initFrame");

    compiler->visit(ctx->block()->compoundStatement());

    emitComment("Call freeFrame");
    emit(JSUB, "freeFrame");   
    emit(LDL, "stack");
    emit(JRET);
}

void ProgramGenerator::emitRoutine(PascalParser::RoutineDefinitionContext *ctx) {
    cout << "emitRoutine" << endl << flush;
    SymtabEntry *routineId = ctx->functionHead()->routineIdentifier()->entry;
    Symtab *routineSymtab = routineId->getRoutineSymtab();

    emitComment("");
    emitComment("ROUTINE: " + routineId->getName());
    emitComment("");

    int varStackSize = emitRoutineLocals(routineId);

    emitComment("Call initFrame");
    emitLabel(routineId->getName());
    emit(LDX, "stackindex");
    emit(STL, "stack, x");
    emit(LDA, varStackSize);
    emit(LDB, routineSymtab->getNestingLevel());
    emit(JSUB, "initFrame");

    PascalParser::CompoundStatementContext *stmtCtx = (PascalParser::CompoundStatementContext *) routineId->getExecutable();
    compiler->visit(stmtCtx);

    emitRoutineReturn(routineId);
}

int ProgramGenerator::emitRoutineLocals(SymtabEntry *routineId) {
    cout << "emitRoutineLocals" << endl << flush;
    Symtab *symtab = routineId->getRoutineSymtab();
    vector<SymtabEntry *> ids = symtab->sortedEntries();

    emitLine();

    int varStackSize = 0;

    for (SymtabEntry *id : ids) {
        Kind kind = id->getKind();

        if ((kind == VARIABLE) || (kind == VALUE_PARAMETER) || (kind == REFERENCE_PARAMETER)) {
            int slot = id->getSlotNumber();
            emit(id->getName(), WORD, slot);
        }
    }

    return 52;
}

void ProgramGenerator::emitRoutineReturn(SymtabEntry *routineId) {
    emitLine();

    // Function: Return the value in the implied function variable.
    if (routineId->getKind() == FUNCTION) {
        Typespec *type = routineId->getType();
        int nestingLevel = routineId->getSymtab()->getNestingLevel();

        // Get the slot number of the function variable.
        string varName = routineId->getName();
        SymtabEntry *varId = routineId->getRoutineSymtab()->lookup(varName);
        int slot = routineId->getSlotNumber();
        emitLoadLocal(type, slot, nestingLevel);
        emitReturnValue(type);
    }
}

}
