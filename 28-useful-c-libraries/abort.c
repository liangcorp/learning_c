#include <stdio.h>
#include <stdlib.h>

FILE *open_file(const char *file)
{
    FILE *in_file;

    if ((in_file = fopen(file, "r")) == NULL) {
        fprintf(stderr, "can't open %s for reading.\n", file);
        abort();    //  abort program and dump core
    }

    return in_file;
}

int main()
{
    return 0;
}
