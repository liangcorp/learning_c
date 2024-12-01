#include <stdio.h>

int main()
{
    FILE *fp = NULL;

    fp = fopen("file.txt", "w+");

    if (fp == NULL) {
        perror("Error in opening file\n");
        return 1;
    }

    fputs("This is Jason Fedin Course.", fp);
    fputs("I am happy to be here", fp);

    fclose(fp);
    fp = NULL;

    return 0;
}
