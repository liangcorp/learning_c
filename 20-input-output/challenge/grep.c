#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int has_char(const char *ch, const char *line) {
    while(*line != '\0') {
        if (*line == *ch)
            return 1;
        line++;
    }

    return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		puts("Invalid number of input arguments.");
		return 1;
	}

	FILE *fp = NULL;
	char *buffer = NULL;
	size_t bufsize = 32;
	size_t characters;

	fp = fopen(argv[2], "r");

	if (fp == NULL) {
		puts("ERROR in opening file.");
		return 1;
	}

	buffer = (char *)malloc(bufsize * sizeof(char));

	if (buffer == NULL) {
		puts("ERROR in allocating memory.");
		return 1;
	}

	while ((characters = getline(&buffer, &bufsize, fp)) != EOF) {
		if (has_char(argv[1], buffer))
			printf("%s", buffer);
	}

	fclose(fp);
	fp = NULL;

	free(buffer);
	buffer = NULL;

	return 0;
}
