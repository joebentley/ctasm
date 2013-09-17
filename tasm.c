#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

    // Read from file until halt, store in src
    int i = 0;
    char c;
    while ((c = fgetc(input)) != EOF) {
        src[i++] = c;
    }

    // Seperate string by newlines
    char ** res = NULL;
    char *  p   = strtok(src, "\n");
    int n_spaces = 0;
    i = 0;

    while (p) {
        res = realloc(res, sizeof (char*) * ++n_spaces);

        if (res == NULL)
            return -1;

        res[n_spaces-1] = p;

        p = strtok(NULL, "\n");
    }

    /*// Set last element to NULL
    res = realloc(res, sizeof (char*) * ++n_spaces);
    res[n_spaces] = 0;*/

    for (i = 0; i < (n_spaces+1); ++i)
        printf ("res[%d] = %s\n", i, res[i]);

    fclose(input);

    return 0;
}
