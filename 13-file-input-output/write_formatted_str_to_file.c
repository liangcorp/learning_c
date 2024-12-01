#include <stdio.h>

int main()
{
    FILE *fp = NULL;

    fp = fopen("file.txt", "w+");

    if (fp == NULL) {
        perror("Error in opening file\n");
        return 1;
    }

    fprintf(fp, "%s %s %s %s %d", "Hello", "my", "number", "is", 555);

    fclose(fp);
    fp = NULL;

    return 0;
}
