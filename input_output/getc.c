#include <stdio.h>

int main(void)
{
    char ch = '\0';

    FILE *fp;

    if (fp = fopen("myfile.txt", "rw"))
    {
        ch = getc(fp);

        while (ch != EOF)
        {
            ch = getc(fp);
        }
        fclose(fp);
    }

    return 0;
}