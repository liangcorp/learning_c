#include <stdio.h>

int main()
{
	FILE *og_fp = NULL;
	FILE *temp_fp = NULL;
	FILE *read_fp = NULL;

	char ch;

	og_fp = fopen("file.txt", "r");

	if (og_fp == NULL) {
		perror("Error in openning original file\n");
		return 1;
	}

	temp_fp = fopen("temp.txt", "w+");

	if (temp_fp == NULL) {
		perror("Error in openning temporary file\n");
		return 1;
	}

	while ((ch = fgetc(og_fp)) != EOF) {
		if (ch < 123 && ch > 96)
			fputc(ch - 32, temp_fp);
		else
			fputc(ch, temp_fp);
	}

	fclose(og_fp);
	fclose(temp_fp);
	og_fp = NULL;
	temp_fp = NULL;

	if (rename("temp.txt", "file.txt") != 0) {
		perror("Fail to rename file\n");
		return 1;
	}

	if (remove("temp.txt") == 0) {
		perror("Fail to delete temp file\n");
		return 1;
	}

	read_fp = fopen("file.txt", "r");

	if (read_fp == NULL) {
		perror("Error in openning original file\n");
		return 1;
	}

	while ((ch = fgetc(read_fp)) != EOF)
		printf("%c", ch);

	fclose(read_fp);
	read_fp = NULL;

	return 0;
}
