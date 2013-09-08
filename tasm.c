#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    FILE *input;
    int opt;

    // Parse options
    while ((opt = getopt(argc, argv, "")) != -1)
    {
        switch (opt)
        {

        }
    }

    // Check if using file, else use stdin
    input = fopen(argv[optind], "r");

    char read[5];

    fgets(read, 5, input);

    puts(read);
    return 0;
}
