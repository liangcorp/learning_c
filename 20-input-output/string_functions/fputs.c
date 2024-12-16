#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("somefile.txt", "w");

    if (fp == NULL)
        return 1;

    fputs("Hello there, I hope this article will help!", fp);

    fclose(fp);
    fp = NULL;

    return 0;
}
