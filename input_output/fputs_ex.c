#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fp = NULL;
    fp = fopen("myfile.txt", "w");

    if (fp == NULL)
        exit(1);
    
    fputs("Hello there, I hope this article will help!", fp);

    fclose(fp);
    
    return 0;
}
