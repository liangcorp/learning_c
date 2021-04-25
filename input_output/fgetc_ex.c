#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
    char c = '\0';

    fp = fopen("myfile.txt", "r");

    if (fp == NULL)
    {
        printf("Could not open file myfile.txt\n");
        return 1;
    }

    printf("Reading the file myfile.txt\n");

    while (1)
    {
        c = fgetc(fp);

        if (c == EOF)
            break;

        printf("%c", c);
    }

    printf("Closing the file myfile.txt\n");
    fclose(fp);

    return 0;
}
