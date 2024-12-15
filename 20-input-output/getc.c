#include <stdio.h>

int main()
{
	char ch = '\0';

    //  Read from file
	FILE *fp = NULL;

	if ((fp = fopen("somefile.c", "rw"))) {
        ch = getc(fp);

        while (ch != EOF) {
            ch = getc(fp);
        }
        fclose(fp);
	}

    fp = NULL;

    //  Read from console
    ch = getc(stdin);
    printf("read in character %c\n", ch);

	return 0;
}
