#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    int ch;

    fp = fopen("file.txt", "w+");

    if (fp == NULL) {
        perror("Error in opening file\n");
        return 1;
    }

    for (ch = 33; ch <= 100; ch++) {
        fputc(ch, fp);
    }

    fclose(fp);
    fp = NULL;

    return 0;
}
