#include <stdio.h>

#define FILENAME "myfile.txt"

int main(void)
{
    FILE *fp = NULL;
    char ch;
    int line_count = 0;

    fp = fopen(FILENAME, "r");
    
    if (fp == NULL)
    {
        printf("File does not exist\n");
        return -1;
    }
    
    while((ch=fgetc(fp)) != EOF)
    {
        if(ch == '\n')
            line_count++;
    }

    fclose(fp);
    fp = NULL;

    printf("Total number of lines are %d\n", line_count);
    
    return 0;
}