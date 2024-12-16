#include <stdio.h>

int main()
{
	char string[] = "Hello\n there";
	int i = 0;

	while (string[i] != '\0') {
		if (string[i] != '\n')
			putchar(string[i]);

		i++;
	}

    putchar('\n');

    int ch = 0;
    while ((ch = getchar()) != EOF)
        putchar(ch);

    /* ungetc() returns EOF previously read back to stdin */
    ungetc(ch, stdin);

    printf("Thank you!\n");

	return 0;
}
