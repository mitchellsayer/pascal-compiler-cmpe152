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
// #include "LocalVariables.h"
// #include "LocalStack.h"

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

// =====================
// General code emitters
// =====================

/**
 * Emit a blank line.
 */
void CodeGenerator::emitLine() {
    *objectFile << endl;;
    objectFile->flush();
}

/**
 * Emit a comment.
 * @param text the comment text.
 */
void CodeGenerator::emitComment(string text) {
    *objectFile << ";" << endl;
    *objectFile << "; " << text << endl;
    *objectFile << ";" << endl;
    objectFile->flush();
}

/**
 * Emit a statement comment.
 * @param ctx the StatementContext.
 */
void CodeGenerator::emitComment(PascalParser::StatementContext *ctx) {
    string text = ctx->getText();
    if (text.length() > 70) text = text.substr(0, 70) + " ...";

    stringstream ss;
    ss << setw(3) << setfill('0') << ctx->getStart()->getLine() << " " << text;
    emitComment(ss.str());
}

void CodeGenerator::emitLabel(Label *label) {
    *objectFile << label << ":" << endl;
    objectFile->flush();
}

void CodeGenerator::emitLabel(int value, Label *label) {
    *objectFile << "\t  " << value << ": " << label << endl;
    objectFile->flush();
}

void CodeGenerator::emitLabel(string value, Label *label) {
    *objectFile << "\t  " << value << ": " << label << endl;
    objectFile->flush();
}

void CodeGenerator::emit(Opcode instruction) {
    *objectFile << "\t" << instruction << endl;
    objectFile->flush();

    // localStack->increase(stackUse(instruction));
    ++count;
}

void CodeGenerator::emit(Opcode instruction, string operand) {
    *objectFile << "\t" << instruction << "\t" << operand << endl;
    objectFile->flush();

    // localStack->increase(stackUse(instruction));
    ++count;
}

void CodeGenerator::emit(Opcode instruction, int operand) {
    *objectFile << "\t" << instruction << "\t" << operand << endl;
    objectFile->flush();

    // localStack->increase(stackUse(instruction));
    ++count;
}

void CodeGenerator::emit(Opcode instruction, double operand) {
    *objectFile << "\t" << instruction << "\t" << operand << endl;
    objectFile->flush();

    // localStack->increase(stackUse(instruction));
    ++count;
}

void CodeGenerator::emit(Opcode instruction, Label *label) {
    *objectFile << "\t" << instruction << "\t" << label << endl;
    objectFile->flush();

    // localStack->increase(stackUse(instruction));
    ++count;
}

void CodeGenerator::emit(Opcode instruction, int operand1, int operand2) {
    *objectFile << "\t" << instruction << "\t" << operand1 << " " << operand2 << endl;
    objectFile->flush();

    // localStack->increase(stackUse(instruction));
    ++count;
}

void CodeGenerator::emit(Opcode instruction, string operand1, string operand2) {
    *objectFile << "\t" << instruction << "\t" << operand1 << " " << operand2 << endl;
    objectFile->flush();

    // localStack->increase(stackUse(instruction));
    ++count;
}

void CodeGenerator::emit(string label, Opcode dtype, int operand) {
    *objectFile << "\t  " << label << " " << dtype << " " << operand << endl;
    objectFile->flush();
}

// =====
// Loads
// =====
void CodeGenerator::emitLoadConstant(int value) {
    emit(LDA, value);
}

void CodeGenerator::emitLoadConstant(double value) {
    emit(LDA, value);
}

void CodeGenerator::emitLoadConstant(string value) {
    emit(LDA, "C"" + value + """);
}

void CodeGenerator::emitLoadValue(SymtabEntry *variableId) {
    Typespec *type = variableId->getType()->baseType();
    Kind kind = variableId->getKind();
    int nestingLevel = variableId->getSymtab()->getNestingLevel();

    // Constant
    if (kind == CONSTANT) {
        Object value = variableId->getValue();

        if (type == Predefined::integerType) {
            emitLoadConstant(value.as<int>());
        } else if (type == Predefined::realType) {
            emitLoadConstant(value.as<float>());
        } else if (type == Predefined::charType) {
            int ch = value.as<char>();
            emitLoadConstant(ch);
        } else  {// string {
            emitLoadConstant(value.as<string>());
        }
    }

    // Program variable.
    else if (nestingLevel == 1) {
        string variableName = variableId->getName();
        string name = programName + "/" + variableName;
        // emit(name, START, typeDescriptor(type));
    }

    // Local variable.
    else {
        int slot = variableId->getSlotNumber();
        emitLoadLocal(type, slot);
    }
}

/**
 * Emit a load instruction for a local variable.
 * @param type the variable's data type.
 * @param index the variable's index into the local variables array.
 */
void CodeGenerator::emitLoadLocal(Typespec *type, int index) {
    Form form = SCALAR;

    if (type != nullptr) {
        type = type->baseType();
        form = type->getForm();
    }

    if ((type == Predefined::integerType)
        || (type == Predefined::booleanType)
        || (type == Predefined::charType))
    {
        switch (index)
        {
            // case 0:  emit(ILOAD_0); break;
            // case 1:  emit(ILOAD_1); break;
            // case 2:  emit(ILOAD_2); break;
            // case 3:  emit(ILOAD_3); break;
            // default: emit(ILOAD, index);
        }
    }
    else if (type == Predefined::realType)
    {
        // switch (index) {
        //     case 0:  emit(FLOAD_0); break;
        //     case 1:  emit(FLOAD_1); break;
        //     case 2:  emit(FLOAD_2); break;
        //     case 3:  emit(FLOAD_3); break;
        //     default: emit(FLOAD, index);
        // }
    }
    else
    {
        // switch (index)
        // {
        //     case 0:  emit(ALOAD_0); break;
        //     case 1:  emit(ALOAD_1); break;
        //     case 2:  emit(ALOAD_2); break;
        //     case 3:  emit(ALOAD_3); break;
        //     default: emit(ALOAD, index);
        // }
    }
}

// ======
// Stores
// ======

void CodeGenerator::emitStoreValue(SymtabEntry *targetId, Typespec *targetType) {
    if (targetId == nullptr) {
        emitStoreToArrayElement(targetType);
    } else {
        emitStoreToUnmodifiedVariable(targetId, targetType);
    }
}

void CodeGenerator::emitStoreToUnmodifiedVariable(SymtabEntry *targetId, Typespec *targetType) {
    int nestingLevel = targetId->getSymtab()->getNestingLevel();
    int slot = targetId->getSlotNumber();

    // Program variable.
    if (nestingLevel == 1)
    {
        string targetName = targetId->getName();
        string name = programName + "/" + targetName;

        emitRangeCheck(targetType);
        emit(STA, targetName);
        // emit(PUTSTATIC, name, typeDescriptor(targetType->baseType()));
    }

    // Local variable.
    else
    {
        emitRangeCheck(targetType);
        emitStoreLocal(targetType->baseType(), slot);
    }
}

void CodeGenerator::emitStoreLocal(Typespec *type, int slot)
{
    Form form = SCALAR;

    if (type != nullptr)
    {
        type = type->baseType();
        form = type->getForm();
    }

    if (   (type == Predefined::integerType)
        || (type == Predefined::booleanType)
        || (type == Predefined::charType)
        || (form == ENUMERATION))
    {
        switch (slot)
        {
            // case 0:  emit(ISTORE_0); break;
            // case 1:  emit(ISTORE_1); break;
            // case 2:  emit(ISTORE_2); break;
            // case 3:  emit(ISTORE_3); break;
            // default: emit(ISTORE, slot);
        }
    }
    else if (type == Predefined::realType)
    {
        switch (slot) {
            // case 0:  emit(FSTORE_0); break;
            // case 1:  emit(FSTORE_1); break;
            // case 2:  emit(FSTORE_2); break;
            // case 3:  emit(FSTORE_3); break;
            // default: emit(FSTORE, slot);
        }
    }
    else
    {
        switch (slot)
        {
            // case 0:  emit(ASTORE_0); break;
            // case 1:  emit(ASTORE_1); break;
            // case 2:  emit(ASTORE_2); break;
            // case 3:  emit(ASTORE_3); break;
            // default: emit(ASTORE, slot);
        }
    }
}

void CodeGenerator::emitStoreToArrayElement(Typespec *elmtType) {
    Form form = SCALAR;

    if (elmtType != nullptr) {
        elmtType = elmtType->baseType();
        form = elmtType->getForm();
    }

    // emit(  elmtType == Predefined::integerType ? IASTORE
    //      : elmtType == Predefined::realType    ? FASTORE
    //      : elmtType == Predefined::booleanType ? BASTORE
    //      : elmtType == Predefined::charType    ? CASTORE
    //      : form == ENUMERATION                 ? IASTORE
    //      :                                       AASTORE);
}

// ======================
// Miscellaneous emitters
// ======================

void CodeGenerator::emitCheckCast(Typespec *type) {
    string descriptor = typeDescriptor(type);

    // Don't bracket the type with L; if it's not an array.
    if (descriptor[0] == 'L') {
        descriptor = descriptor.substr(1, descriptor.length() - 2);
    }

    // emit(CHECKCAST, descriptor);
}

void CodeGenerator::emitCheckCastClass(Typespec *type) {
    string descriptor = objectTypeName(type);

    // Don't bracket the type with L; if it's not an array.
    if (descriptor[0] == 'L') {
        descriptor = descriptor.substr(1, descriptor.length() - 2);
    }

    // emit(CHECKCAST, descriptor);
}

void CodeGenerator::emitReturnValue(Typespec *type) {
    Form form = SCALAR;

    if (type != nullptr) {
        type = type->baseType();
        form = type->getForm();
    }

//     if (   (type == Predefined::integerType)
//         || (type == Predefined::booleanType)
//         || (type == Predefined::charType)
//         || (form == ENUMERATION))          emit(IRETURN);
//     else if (type == Predefined::realType) emit(FRETURN);
//     else                                   emit(ARETURN);
}

void CodeGenerator::emitRangeCheck(Typespec *targetType) {
//        if (targetType.getForm() == SUBRANGE)
//        {
//            int min = targetType.getSubrangeMinValue();
//            int max = targetType.getSubrangeMaxValue();
//
//            emit(DUP);
//            emitLoadConstant(min);
//            emitLoadConstant(max);
//            emit(INVOKESTATIC, "RangeChecker/check(III)V");
//
//            localStack->use(3);
//        }
}

// =========
// Utilities
// =========

string CodeGenerator::typeDescriptor(SymtabEntry *id) {
    Typespec *type = id->getType();
    return type != nullptr ? typeDescriptor(type) : "V";
}

string CodeGenerator::typeDescriptor(Typespec *pascalType) {
    Form form = pascalType->getForm();
    string descriptor;

    while (form == ARRAY) {
        descriptor += "[";
        pascalType =  pascalType->getArrayElementType();
        form = pascalType->getForm();
    }

    pascalType = pascalType->baseType();
    string str;

    // if      (pascalType == Predefined::integerType) str = "I";
    // else if (pascalType == Predefined::realType)    str = "F";
    // else if (pascalType == Predefined::booleanType) str = "Z";
    // else if (pascalType == Predefined::charType)    str = "C";
    // else if (pascalType == Predefined::stringType)  str = "Ljava/lang/String;";
    // else if (form == ENUMERATION)                  str = "I";
    // else /* (form == RECORD) */ str = "L" + pascalType->getRecordTypePath() + ";";

    // descriptor += str;
    // return descriptor;
}

string CodeGenerator::objectTypeName(Typespec *pascalType) {
    Form form = pascalType->getForm();
    string typeName;
    bool isArray = false;

    while (form == ARRAY) {
        typeName += "[";
        pascalType = pascalType->getArrayElementType();
        form = pascalType->getForm();
        isArray = true;
    }

    if (isArray)  typeName += "L";

    pascalType = pascalType->baseType();
    string str;

    // if      (pascalType == Predefined::integerType) str = "java/lang/Integer";
    // else if (pascalType == Predefined::realType)    str = "java/lang/Float";
    // else if (pascalType == Predefined::booleanType) str = "java/lang/Boolean";
    // else if (pascalType == Predefined::charType)    str = "java/lang/Character";
    // else if (pascalType == Predefined::stringType)  str = "Ljava/lang/String;";
    // else if (form == ENUMERATION)                  str = "java/lang/Integer";
    // else /* (form == RECORD) */ str = "L" + pascalType->getRecordTypePath() + ";";

    // typeName += str;
    // if (isArray) typeName += ";";

    // return typeName;
}

bool CodeGenerator::needsCloning(SymtabEntry *formalId) {
    Typespec *type = formalId->getType();
    Form form = type->getForm();
    Kind kind = formalId->getKind();

    // Arrays and records are normally passed by reference
    // and so must be cloned to be passed by value.
    return ((kind == VALUE_PARAMETER)) && ((form == ARRAY));
}

string CodeGenerator::valueOfSignature(Typespec *type) {
    string javaType = objectTypeName(type);
    string typeCode = typeDescriptor(type);

    stringstream ss;
    ss << javaType << "/valueOf(" << typeCode << ")L" << javaType << ";";

    return ss.str();
}

string CodeGenerator::valueSignature(Typespec *type) {
    string javaType = objectTypeName(type);
    string typeCode = typeDescriptor(type);
    string typeName = type == Predefined::integerType ? "int"
                    : type == Predefined::realType    ? "double"
                    : type == Predefined::booleanType ? "boolean"
                    : type == Predefined::charType    ? "char"
                    :                                   "int";

    stringstream ss;
    ss << javaType << "." << typeName << "Value()" << typeCode;

    return ss.str();
}

}