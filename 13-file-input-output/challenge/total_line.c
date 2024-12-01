#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    char c;
    int counter = 0;

    fp = fopen("file.txt", "r");

    if (fp == NULL) {
        perror("Error in openning file.\n");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF)
        if (c == '\n')
            counter++;

    printf("There are %d line of text in file\n", counter);

    fclose(fp);
    fp = NULL;

    return 0;
}

