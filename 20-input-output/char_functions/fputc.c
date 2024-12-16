#include <stdio.h>

int main()
{
	FILE *p_file = NULL;
	char c;

	p_file = fopen("myfile.txt", "w");

	if (p_file != NULL) {
		for (c = 'A'; c <= 'Z'; c++)
			fputc(c, p_file);

		fclose(p_file);
		p_file = NULL;
	}

	if (p_file != NULL)
		for (c = 'A'; c <= 'Z'; c++)
			fputc(c, stdout);

	return 0;
}
