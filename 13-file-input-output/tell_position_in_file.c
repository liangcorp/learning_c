#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    int len;

    fp = fopen("file.txt", "r");

    if (fp == NULL) {
        perror("Error openning file\n");
        return -1;
    }

    fseek(fp, 0, SEEK_END);

    len = ftell(fp);
    fclose(fp);
    fp = NULL;

    printf("Total size of file.txt = %d bytes\n", len);

    return 0;
}
