/*
StackFrame contains routine's local memory
    - maintains current runtime values of local variables
    - maintains current runtime values of formal parameters
    - can be a procedure, function, or main program itself

The stack frame for a routine (procedure, function, or the main program) needs one or more 
data cells to store the runtime value of each of the routine’s local variables and 
formal parameters.

Obtain the names and types of the local variables and formal parameters from the 
routine’s symbol table.

Whenever we call a procedure or function:
    1. Create a stack frame.
    2. Push the stack frame onto the runtime stack.
    3. Allocate the memory for data cells based on the symbol table.

Value parameters: A copy of the value is passed.
VAR parameters: A reference to the actual parameter is passed.

Final StackFrame:
    - Return Address
    - Scope Level
    - Index to previous stack frame
    - Space for all parameters and local variables
*/

#ifndef STACKFRAME_H_
#define STACKFRAME_H_

namespace backend {

using namespace std;

class StackFrame {
private:
    uint8_t return_addr;
    int scope_level;
    int prev_stack_idx;

    map<string, VALUE?> local_memory;

public:
    StackFrame() : size(0), maxSize(0) {}

    
};

}

#endif