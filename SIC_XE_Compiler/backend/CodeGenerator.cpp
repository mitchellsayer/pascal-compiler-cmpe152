#include <fstream>
#include <sstream>
#include <iomanip>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "CodeGenerator.h"
#include "Label.h"
#include "Opcode.h"

namespace backend {

using namespace std;
using namespace intermediate;

int Label::index = 0;
int CodeGenerator::count = 0;

void CodeGenerator::open(string programName, string suffix) {
    objectFileName = programName + "." + suffix;
    objectFile = new ofstream(objectFileName);

    if (!objectFile->is_open()) {
        cout << "ERROR: object file open failed: \"" << objectFileName << "\"." << endl;
        exit(-1);
    }
}

void CodeGenerator::emitLine() {
    *objectFile << endl;;
    objectFile->flush();
}

void CodeGenerator::emitComment(string text) {
    *objectFile << "; " << text << endl;
    objectFile->flush();
}

void CodeGenerator::emitComment(PascalParser::StatementContext *ctx) {
    string text = ctx->getText();
    if (text.length() > 70) text = text.substr(0, 70) + " ...";

    stringstream ss;
    ss << setw(3) << setfill('0') << ctx->getStart()->getLine() << " " << text;
    emitComment(ss.str());
}

void CodeGenerator::emitComment(PascalParser::CompoundStatementContext *ctx) {
    string text = ctx->statementList()->statement()[0]->getText();
    if (text.length() > 70) text = text.substr(0, 70) + " ...";

    stringstream ss;
    ss << setw(3) << setfill('0') << ctx->getStart()->getLine() << " " << text;
    emitComment(ss.str());
}

void CodeGenerator::emitLabel(Label *label) {
    *objectFile << label; //<< endl;
    objectFile->flush();
}

void CodeGenerator::emitLabel(string label) {
    *objectFile << label; //<< endl;
    objectFile->flush();
}

void CodeGenerator::emitLabel(string value, Label *label) {
    *objectFile << "\t" << value << "\t" << label;
    objectFile->flush();
}

void CodeGenerator::emit(Opcode instruction) {
    *objectFile << "\t" << instruction << "\t" << endl;
    objectFile->flush();
    ++count;
}

void CodeGenerator::emit(Opcode instruction, string operand) {
    *objectFile << "\t" << instruction << "\t" << operand << endl;
    objectFile->flush();
    ++count;
}

void CodeGenerator::emit(Opcode instruction, int operand) {
    *objectFile << "\t" << instruction << "\t" << operand << endl;
    objectFile->flush();
    ++count;
}

void CodeGenerator::emit(Opcode instruction, double operand) {
    *objectFile << "\t" << instruction << "\t" << operand << endl;
    objectFile->flush();
    ++count;
}

void CodeGenerator::emit(Opcode instruction, int operand1, int operand2) {
    *objectFile << "\t" << instruction << "\t" << operand1 << " " << operand2 << endl;
    objectFile->flush();
    ++count;
}

void CodeGenerator::emit(Opcode instruction, string operand1, string operand2) {
    *objectFile << "\t" << instruction << "\t" << operand1 << ", " << operand2 << endl;
    objectFile->flush();
    ++count;
}

void CodeGenerator::emit(string label, Opcode dtype, int operand) {
    *objectFile << label << "\t" << dtype << "\t" << operand << endl;
    objectFile->flush();
}

void CodeGenerator::emitLoadConstant(int value, int offset, int nestingLevel) {
    emit(LDA, nestingLevel);
    emit(JSUB, "findstackframe"); // Returns the stack from address in A
    emit(ADD, offset); //Add offset within frame
    emit(CLEAR, "X");
    emit(ADDR, "A", "X");
    emit(LDA, value);
    emit(STA, 'stack,x');
}

void CodeGenerator::emitLoadConstant(double value, int offset, int nestingLevel) {
    emit(LDA, nestingLevel);
    emit(JSUB, "findstackframe"); // Returns the stack from address in A
    emit(ADD, offset); //Add offset within frame
    emit(CLEAR, "X");
    emit(ADDR, "A", "X");
    emit(LDF, value);
    emit(STF, "stack,x");
}

void CodeGenerator::emitLoadConstant(string value, int offset, int nestingLevel) {
    emit(LDA, nestingLevel);
    emit(JSUB, "findstackframe"); // Returns the stack from address in A
    emit(ADD, offset); //Add offset within frame
    emit(CLEAR, "X");
    emit(ADDR, "A", "X");
    emit(LDA, "C"" + value + """);
    emit(STA, 'stack,x');
}

void CodeGenerator::emitLoadValue(SymtabEntry *variableId) {
    Typespec *type = variableId->getType()->baseType();
    Kind kind = variableId->getKind();
    int nestingLevel = variableId->getSymtab()->getNestingLevel();

    int offset = nestingLevel;

    // Constant
    if (kind == CONSTANT) {
        Object value = variableId->getValue();

        if (type == Predefined::integerType) {
            emitLoadConstant(value.as<int>(), offset, nestingLevel);
        } else if (type == Predefined::realType, offset, nestingLevel) {
            emitLoadConstant(value.as<float>(), offset, nestingLevel);
        } else if (type == Predefined::charType, offset, nestingLevel) {
            int ch = value.as<char>();
            emitLoadConstant(ch, offset, nestingLevel);
        }
    }

    // Local variable.
    else {
        int slot = variableId->getSlotNumber();
        string name = variableId->getName();
        emitLoadLocal(type, slot, nestingLevel);
    }
}

void CodeGenerator::emitLoadLocal(Typespec *type, int slot, int nestingLevel) {
    Form form = SCALAR;
    if (type != nullptr) {
        type = type->baseType();
        form = type->getForm();
    }

    int offset = slot;

    emit(LDA, nestingLevel);
    emit(JSUB, "findstackframe"); // Returns the stack from address in A
    emit(ADD, offset); //Add offset within frame
    emit(CLEAR, "X");
    emit(ADDR, "A", "X");

    if ((type == Predefined::integerType) || (type == Predefined::booleanType) || (type == Predefined::charType)) {
        emit(LDA, "stack, x");
    } else if (type == Predefined::realType) {
        emit(LDF, "stack, x");
    }
}


void CodeGenerator::emitStoreValue(SymtabEntry *targetId, Typespec *targetType) {
    int nestingLevel = targetId->getSymtab()->getNestingLevel();
    int slot = targetId->getSlotNumber();

    if (targetId != nullptr) {
        emitStoreLocal(targetType->baseType(), slot, nestingLevel);
    }
}

void CodeGenerator::emitStoreLocal(Typespec *type, int slot, int nestingLevel) {
    Form form = SCALAR;

    int offset = slot; // symboltable[slot]

    if (type != nullptr) {
        type = type->baseType();
        form = type->getForm();
    }

    // Get offset for new variable
    emitComment("Load Variable Offset");
    emit(LDA, nestingLevel);
    emit(JSUB, "findstackframe"); // Returns the stack from address in A
    emit(ADD, offset); //Add offset within frame
    emit(CLEAR, "T");
    emit(ADDR, "A", "T");

    emitComment("Pop Stack & Store value");
    if ((type == Predefined::integerType) || (type == Predefined::booleanType) || (type == Predefined::charType)) {
        emit(LDA, "stackindex");
        emit(SUB, 3);
        emit(STA, "stackindex");
        emit(LDX, "stackindex");
        emit(STA, "stack,x");
        emit(LDX, "T");
        emit(STA, "stack,x");
    } else if (type == Predefined::realType) {
        emit(LDA, "stackindex");
        emit(SUB, 6);
        emit(STA, "stackindex");
        emit(LDX, "stackindex");
        emit(STF, "stack,x");
        emit(LDX, "T");
        emit(STF, "stack,x");
    }
}

void CodeGenerator::emitReturnValue(Typespec *type) {
    Form form = SCALAR;

    if (type != nullptr) {
        type = type->baseType();
        form = type->getForm();
    }

    if ((type == Predefined::integerType) || (type == Predefined::booleanType)
        || (type == Predefined::charType)) emit(STA, 'returnvalue');
    else if (type == Predefined::realType) emit(STF, 'returnvalue');
}

}