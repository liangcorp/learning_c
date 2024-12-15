#include <stdio.h>

void count_file(FILE *fp)
{
	int no_of_word = 0;
	int no_of_char = 0;
	int ch = 0;

	ch = getc(fp);

	while (ch != EOF) {
		if (ch == ' ' || ch == '\n')
			no_of_word++;
		else
			no_of_char++;

        ch = getc(fp);
	}

	printf("The number of words in the file are: %d\n", no_of_word);
	printf("The number of characters in the file are: %d\n", no_of_char);
}

void count_stdout()
{
	int no_of_word = 0;
	int no_of_char = 0;
	int ch = 0;

	ch = getchar();

	while (ch != EOF) {
		if (ch == ' ' || ch == '\n')
			no_of_word++;
		else
			no_of_char++;

		ch = getchar();
	}

	printf("The number of words in stdout are: %d\n", no_of_word);
	printf("The number of characters in stdout are: %d\n", no_of_char);
}

int main(int argc, char *argv[])
{

	if (argc == 1) {
		count_stdout();
	} else if (argc == 2) {
        FILE *fp = NULL;
		fp = fopen(argv[1], "r");

		if (fp == NULL) {
			printf("ERROR: can not open file to write\n");
			return 1;
		}

		count_file(fp);
        fclose(fp);
        fp = NULL;
	} else {
		printf("Invalid number of arguments\n");
	}


	return 0;
}
