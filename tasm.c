#include <stdio.h>
#include <unistd.h>
#include "instructs.h"

int main(int argc, char* argv[]) {
    FILE *input;
    int opt;

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

    char read[5];

    fgets(read, 5, input);

    puts(read);
    return 0;
}
