#include "instructs.h"

typedef struct {
    char* name;
    int arg1, arg2, arg3;
    int opcode;
} ins_t;

/* 0 = no arg
 * 1 = pointer ( [x] )
 * 2 = literal (  x  ) */
ins_t instructions[] = {

};

int get_opcode(char* name, int arg1, int arg2, int arg3) {
    return 0;
}
