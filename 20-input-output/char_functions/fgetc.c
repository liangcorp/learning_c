#include <stdio.h>

int main()
{
	FILE *fp = NULL;

	char ch = '\0';

	fp = fopen("myfile.c", "r");

	if (fp == NULL) {
		printf("Could not open file myfile.c");
		return 1;
	}

	printf("Reading the file myfile.c\n");

	while (1) {
		ch = fgetc(fp);

		if (ch == EOF)
			break;

		printf("%c", ch);
	}

	fclose(fp);
	fp = NULL;

	return 0;
}
