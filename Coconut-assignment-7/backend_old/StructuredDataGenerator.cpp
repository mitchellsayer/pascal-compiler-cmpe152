#include <string>
#include <vector>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "Compiler.h"
#include "Instruction.h"
#include "CodeGenerator.h"
#include "ExpressionGenerator.h"
#include "StructuredDataGenerator.h"

namespace backend {

using namespace std;

/**
 * Emit code to allocate the string, array, and record variables
 * of a program, procedure, or function.
 * @param routineId the routine's symbol table entry.
 */
void StructuredDataGenerator::emitData(SymtabEntry *routineId) {
    Symtab *symtab = routineId->getRoutineSymtab();
    vector<SymtabEntry *> ids = symtab->sortedEntries();

    // Loop over all the symbol table's identifiers to emit
    // data allocation code for array and record variables.
    for (SymtabEntry *id : ids) {
        if (id->getKind() == VARIABLE) {
            Typespec *type = id->getType();
            Form form = type->getForm();

            if (form == ARRAY)  emitAllocateArray(id, type);
        }
    }
}

/**
 * Emit code to allocate an array for a target variable or field.
 * @param targetId the target variable's or field's symbol table entry.
 * @param arrayType the array type.
 */
void StructuredDataGenerator::emitAllocateArray(SymtabEntry *targetId, Typespec *arrayType) {
    Typespec *elmtType = arrayType;
    int dimensionCount = 0;

    // Count the dimensions and emit a load constant of each element count.
    emitLine();
    do {
        int elmtCount = elmtType->getArrayElementCount();
        ++dimensionCount;
        emitLoadConstant(elmtCount);
        elmtType = elmtType->getArrayElementType();
    } while (elmtType->getForm() == ARRAY);

    // The array element type.
    elmtType = elmtType->baseType();
    Form elmtForm = elmtType->getForm();
    string typeName =
          elmtType == Predefined::integerType ? "int"
        : elmtType == Predefined::realType    ? "float"
        : elmtType == Predefined::booleanType ? "bool"
        : elmtType == Predefined::charType    ? "char"
        : elmtType == Predefined::stringType  ? "java/lang/String"
        : elmtForm == ENUMERATION             ? "int"
        : elmtForm == RECORD                  ? elmtType->getIdentifier()
                                                        ->getName()
        :                                       nullptr;

    // One-dimensional array.
    if (dimensionCount == 1) {
        if (elmtType->getForm() == RECORD) {
            emit(ANEWARRAY, elmtType->getRecordTypePath());
            emit(DUP);
        } else if (elmtType == Predefined::stringType) {
            emit(ANEWARRAY, typeName);
        } else {
            emit(NEWARRAY, typeName);
        }
    }

    // Multidimensional array.
    else {
        emit(MULTIANEWARRAY, typeDescriptor(targetId->getType()), to_string(dimensionCount));
        localStack->decrease(dimensionCount - 1);

        if (elmtType->getForm() == RECORD) emit(DUP);
    }

    // Store the allocation into the array variable.
    emitStoreValue(targetId, targetId->getType());

    // Allocate data for record elements.
    if (elmtType->getForm() == RECORD) {
        emitAllocateArrayElements(targetId, targetId->getType(), 1, dimensionCount);
        emit(POP);
    }
}

void StructuredDataGenerator::emitAllocateArrayElements(
                                    SymtabEntry *targetId, Typespec *elmtType,
                                    int dimensionIndex, int dimensionCount) {
    int count = elmtType->getArrayElementCount();
    int tempIndex = localVariables->reserve();  // temporary loop variable
    Label *loopStartLabel = new Label();
    Label *loopExitLabel  = new Label();

    // Initialize temporary variable to 0.
    emitLoadConstant(0);
    emitStoreLocal(Predefined::integerType, tempIndex);

    // Top of the loop:
    // Compare the temporary variable to the element count.
    emitLabel(loopStartLabel);
    emitLoadLocal(Predefined::integerType, tempIndex);
    emitLoadConstant(count);
    emit(IF_ICMPGE, loopExitLabel);
    emitLine();
    emit(DUP);

    Form form = elmtType->getArrayElementType()->getForm();

    // Allocate data for the next array dimension.
    if (form == ARRAY) {
        emitLoadLocal(Predefined::integerType, tempIndex);   // subscript
        emit(AALOAD);
        emitAllocateArrayElements(targetId, elmtType->getArrayElementType(),
                                  dimensionIndex + 1, dimensionCount);
    }

    // Allocate data for a record element.
    else if (form == RECORD) {
        emitLoadLocal(Predefined::integerType, tempIndex);  // subscript
        emitAllocateRecord(nullptr, elmtType->getArrayElementType(), DUP_X2);
    }

    // Bottom of the loop:
    // If it's not the last dimension, pop off the copy of the record
    // address used by that dimension.
    if (dimensionIndex != dimensionCount) emit(POP);

    // Increment the temporary variable and branch back to the top
    // of the loop.
    emit(IINC, tempIndex, 1);
    emit(GOTO, loopStartLabel);
    emitLabel(loopExitLabel);

    localVariables->release(tempIndex);
}

}
