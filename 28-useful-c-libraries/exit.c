#include <stdio.h>
#include <stdlib.h>

FILE *open_file(const char *file)
{
    FILE *in_file;

    if ((in_file = fopen(file, "r")) = NULL) {
        fprintf(stderr, "Can't open %s for reading.\n", file);
        exit(EXIT_FAILURE); // exit()
    }
}

int main()
{
    return 0;
}
