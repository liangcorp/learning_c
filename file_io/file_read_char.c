#include <stdio.h>

int main(void)
{
    FILE *fp;
    int c;

    fp = fopen("myfile.txt", "r");

    if(fp == NULL)
    {
        perror("Error in opening file");
        return -1;
    }

    // read a single char
    while((c = fgetc(fp)) != EOF)
        printf("%c", c);

    fclose(fp);
    fp = NULL;

    return 0;
}
