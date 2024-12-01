#include <stdio.h>

int main()
{
    FILE *pfile = NULL;

    char *filename = "myfile.txt";

    pfile = fopen(filename, "w");   // Open myfile.txt to write

    if (pfile != NULL) {
        printf("Fail to open %s.\n", filename);
        return 1;
    }

    fclose(pfile);
    pfile = NULL;

    return 0;
}
