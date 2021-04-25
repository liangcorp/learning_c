#include <stdio.h>

int main(void)
{
    FILE *fp;
    fpos_t position;

    fp = fopen("myfile.txt", "w+");
    fgetpos(fp, &position);
    fputs("Hello, World!", fp);

    fclose(fp);

    return 0;
}
