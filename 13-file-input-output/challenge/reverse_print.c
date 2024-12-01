#include <stdio.h>

int main()
{
	FILE *fp = NULL;
	int len;
	int i = 0;

	fp = fopen("file.txt", "r");

	if (fp == NULL) {
		perror("Error openning file\n");
		return -1;
	}

	//  Move file pointer to the end of file
	fseek(fp, 0, SEEK_END);
	//  Get position (end of file)
	len = ftell(fp);

	while (i < len) {
		i++;
		fseek(fp, -i, SEEK_END);
		printf("%c", fgetc(fp));
	}

	printf("\n");

	fclose(fp);
	fp = NULL;

	return 0;
}
