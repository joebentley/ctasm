#include <stdio.h>
#include <unistd.h>

#include "instructs.h"

int main(int argc, char* argv[]) {
    FILE *input;
    int opt;
    char src[5000];

    // Parse options
    while ((opt = getopt(argc, argv, "")) != -1) {
        switch (opt) {

        }
    }

    // Check if using file, else use stdin
    if (optind >= argc)
        input = stdin;
    else {
        input = fopen(argv[optind], "r"); 
        if (input == NULL) {
            printf("Couldn't open file\n");
            return -1;
        }
    }

    // Read from file until halt
    int i = 0;
    char c;
    while ((c = fgetc(input)) != EOF) {
        src[i++] = c;
    }

    fclose(input);

    printf(src);
    return 0;
}
