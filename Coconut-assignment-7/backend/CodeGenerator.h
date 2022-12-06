#ifndef COMPILER_CODEGENERATOR_H_
#define COMPILER_CODEGENERATOR_H_

#include <fstream>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"
#include "Label.h"
#include "Opcode.h"
// #include "LocalVariables.h"
// #include "LocalStack.h"

namespace backend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;

class Compiler;

class CodeGenerator {
private:
    string objectFileName;

protected:
    ofstream *objectFile;
    string programName;
    // LocalVariables *localVariables;
    // localStack *localStack;
    Compiler *compiler;

    static int count;

public:
    CodeGenerator(string programName, string suffix, Compiler *compiler): 
        objectFile(nullptr), 
        programName(programName),
        // localVariables(nullptr), 
        // localStack(nullptr),
        compiler(nullptr) 
    {
    	open(programName, suffix);
	}

    CodeGenerator(CodeGenerator *parent, Compiler *compiler): 
        objectFile(parent->objectFile), 
        programName(parent->programName),
        // localVariables(parent->localVariables),
        // localStack(parent->localStack),
        compiler(compiler) {}

    string getObjectFileName() const { return objectFileName; }

    void open(string programName, string suffix);

    void close() { objectFile->close(); }

    void emitLine();

    void emitComment(string text);

    void emitComment(PascalParser::StatementContext *ctx);

    void emitLabel(Label *label);

    void emitLabel(int value, Label *label);

    void emitLabel(string value, Label *label);

    // void emitDirective(Directive directive);

    // void emitDirective(Directive directive, string operand);

    // void emitDirective(Directive directive, int operand);

    // void emitDirective(Directive directive, string operand1, string operand2);

    // void emitDirective(Directive directive, string operand1, string operand2, string operand3);

    void emit(Opcode instruction);

    void emit(Opcode instruction, string operand);

    void emit(Opcode instruction, int operand);

    void emit(Opcode instruction, double operand);

    void emit(Opcode instruction, Label *label);

    void emit(Opcode instruction, int operand1, int operand2);

    void emit(Opcode instruction, string operand1, string operand2);

    void emit(string label, Opcode dtype, int operand);

    // =====
    // Loads
    // =====
    void emitLoadConstant(int value);

    void emitLoadConstant(double value);

    void emitLoadConstant(string value);

    void emitLoadValue(SymtabEntry *variableId);

    void emitLoadLocal(Typespec *type, int index);

    // ======
    // Stores
    // ======

    void emitStoreValue(SymtabEntry *targetId, Typespec *targetType);

    void emitStoreLocal(Typespec *type, int slot);

    // ======================
    // Miscellaneous emitters
    // ======================

    void emitCheckCast(Typespec *type);

    void emitCheckCastClass(Typespec *type);

    void emitReturnValue(Typespec *type);

    void emitRangeCheck(Typespec*targetType);

    // =========
    // Utilities
    // =========
    string typeDescriptor(SymtabEntry *id);

    string typeDescriptor(Typespec *pascalType);

    string objectTypeName(Typespec *pascalType);

    bool needsCloning(SymtabEntry *formalId);

    string valueOfSignature(Typespec *type);

    string valueSignature(Typespec *type);

private:
    void emitStoreToUnmodifiedVariable(SymtabEntry *targetId, Typespec *targetType);

    void emitStoreToArrayElement(Typespec *elmtType);
};

}

#endif
