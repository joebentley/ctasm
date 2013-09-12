#include "instructs.h"
#include <string.h>

typedef struct {
    char* name;
    arg_t arg1, arg2, arg3;
    int opcode;
} ins_t;

ins_t instructions[] = {
    {"and",    PTR, PTR, NON, 0x00},
    {"and",    PTR, LIT, NON, 0x01},
    {"or",     PTR, PTR, NON, 0x02},
    {"or",     PTR, LIT, NON, 0x03},
    {"xor",    PTR, PTR, NON, 0x04},
    {"xor",    PTR, LIT, NON, 0x05},
    {"not",    PTR, NON, NON, 0x06},
    {"mov",    PTR, PTR, NON, 0x07},
    {"mov",    PTR, LIT, NON, 0x08},
    {"random", PTR, NON, NON, 0x09},
    {"add",    PTR, PTR, NON, 0x0a},
    {"add",    PTR, LIT, NON, 0x0b},
    {"sub",    PTR, PTR, NON, 0x0c},
    {"sub",    PTR, LIT, NON, 0x0d},
    {"jmp",    PTR, NON, NON, 0x0e},
    {"jmp",    LIT, NON, NON, 0x0f},
    {"jz",     PTR, PTR, NON, 0x10},
    {"jz",     PTR, LIT, NON, 0x11},
    {"jz",     LIT, PTR, NON, 0x12},
    {"jz",     LIT, LIT, NON, 0x13},
    {"jeq",    PTR, PTR, PTR, 0x14},
    {"jeq",    LIT, PTR, PTR, 0x15},
    {"jeq",    PTR, PTR, LIT, 0x16},
    {"jeq",    LIT, PTR, LIT, 0x17},
    {"jls",    PTR, PTR, PTR, 0x18},
    {"jls",    LIT, PTR, PTR, 0x19},
    {"jls",    PTR, PTR, LIT, 0x1a},
    {"jls",    LIT, PTR, LIT, 0x1b},
    {"jgt",    PTR, PTR, PTR, 0x1c},
    {"jgt",    LIT, PTR, PTR, 0x1d},
    {"jgt",    PTR, PTR, LIT, 0x1e},
    {"jgt",    LIT, PTR, LIT, 0x1f},
    {"halt",   NON, NON, NON, 0xff},
    {"aprint", PTR, NON, NON, 0x20},
    {"aprint", LIT, NON, NON, 0x21},
    {"dprint", PTR, NON, NON, 0x22},
    {"dprint", LIT, NON, NON, 0x23}
};

int get_opcode(char* name, arg_t arg1, arg_t arg2, arg_t arg3) {
    // Iterate through array, sizeof array / sizeof one instruction = length
    int i = 0;
    for (i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++) {
        // Return opcode if all args are correct for current struct 
        if (strcmp(instructions[i].name, name) == 0 && instructions[i].arg1 == arg1 &&
            instructions[i].arg2 == arg2 && instructions[i].arg3 == arg3)
            return instructions[i].opcode;
        
    }
    return -1;
}
