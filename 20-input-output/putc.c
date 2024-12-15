#include <stdio.h>

int main()
{
    char ch = '\0';
    FILE *fp = NULL;

    //  print to stdout
    putc('d', stdout);

    //  print to file
    if ((fp = fopen("myfile.txt", "rw"))) {
        ch = getc(fp);

        while (ch != EOF) {
            putc(ch, fp);
            ch = getc(fp);
        }
    }

    fclose(fp);
    fp = NULL;

    return 0;
}
