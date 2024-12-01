#include <stdio.h>

int main()
{
    FILE *fp = NULL;

    fp = fopen("file.txt", "w+");
    fputs("This is Jason", fp);

    fseek(fp, 7, SEEK_SET);
    fputs("Hello how are you", fp);

    fclose(fp);
    fp = NULL;

    return 0;
}
