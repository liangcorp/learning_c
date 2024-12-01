#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    fpos_t position;

    fp = fopen("file.txt", "w+");
    fgetpos(fp, &position);
    fputs("Hello, World!", fp);

    fclose(fp);
    fp = NULL;

    return 0;
}
