#ifndef INSTRUCTS_H
#define INSTRUCTS_H

/* NON: no argument
 * PTR: reference to address
 * LIT: literal value */
typedef enum {
    NON = 0,
    PTR = 1,
    LIT = 2
} arg_t;

// Return opcode based on name (assembly instruction) and argument types
int get_opcode(char* name, arg_t arg1, arg_t arg2, arg_t arg3);

#endif
