#include <stdio.h>

int main(void)
{
    FILE *fp = NULL;

    fp = fopen("myfile.txt", "w+");
    fputs("This is Jason", fp);

    fseek(fp, 7, SEEK_SET);
    fputs("Hello how are you", fp);
    fclose(fp);

    return 0;
}
