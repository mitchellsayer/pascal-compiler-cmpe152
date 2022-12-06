/*
RuntimeStack

- A pre-allocated area of memory
- When entering a subroutine, we PUSH a “stack frame” which will 
    contain local parameters and storage
- Pushing a stack frame really means adjusting the stack pointer
- The compiler determines the size of the stack frame by adding 
    the sizes of all the elements in the function’s symbol table
- When exiting the function, we POP the stack frame (adjust the stack pointer)

To access the value of a variable at nesting level n, the value must come from 
the topmost stack frame at level n.

At top of function:
    - Push the stack frame
    - Actually just move the stack pointer
    - Rather than a stack pointer, I recommend a stack index
    - To access a local variable:
        - X = stackindex + variable offset
        - LDA stack, X
    - Store return address (L)
    - Store scope level

At Bottom of function:
    - Store Return Value (for function)
    - Load return address into L register
    - POP the stack frame (decrement the stack index)
    - Return (RSUB)

InitializeFrame function:
Parameters:
    - A = number of bytes of store needed (not counting return location and scope level)
    - B – scope level
Procedure:
    - Check stack index against max *
    - Check display index against max *
    - Update stack index
    - Insert scope into stack frame
    - Insert previous frame index into stack frame
    - Update display index
    - Update display

    * If an overflow occurs, print an error and exit the program

A “free frame” function that is called at the end of a function or procedure
- Updates display
- Updates the stack index (sets to previous index value)

*/

#ifndef RUNTIMESTACK_H_
#define RUNTIMESTACK_H_

#include <algorithm>
#include "StackFrame.h"

namespace backend {

using namespace std;

class LocalStack {
private:
    int size;     // current stack size
    int maxSize;  // maximum attained stack size
    // vector<int> display_vec;

public:
    LocalStack() : size(0), maxSize(0) {}

    void initializeFrame() {

    }

    void freeFrame() {

    }

    void reset() {
        this->size = 0;
        this->maxSize = 0;
    }

    int getSize() const { return size; }

    void increase(const int amount) {
        size += amount;
        maxSize = max(maxSize, size);
    }

    void decrease(const int amount) {
        size -= amount;
        if (size < 0) size = 0;
    }

    int capacity() const { return maxSize; }
};

}

#endif