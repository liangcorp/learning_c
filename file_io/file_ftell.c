#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;
    int len;

    fp = fopen("myfile.txt", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    fseek(fp, 0, SEEK_END);

    len = ftell(fp);
    fclose(fp);

    printf("Total size of file.txt = %d bytes\n", len);

    return 0;
}