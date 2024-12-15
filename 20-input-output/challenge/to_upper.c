#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("ERROR: invalid number of arguments: %d. Needs 1 \n", argc - 1);
        return 1;
    }

    FILE *fp_origin = NULL;
    FILE *fp_temp = NULL;

    int ch = 0;

    fp_origin = fopen(argv[1], "r");
    fp_temp = fopen("temp.txt", "w");

	if (fp_origin == NULL) {
		printf("Could not open file %s\n", argv[1]);
		return 1;
	}

	if (fp_temp == NULL) {
		printf("Could not open file temp.txt to write\n");
		return 1;
	}

	while (1) {
		ch = fgetc(fp_origin);

		if (ch == EOF)
			break;

        if (ch > 96 && ch < 123)
			fputc(ch - 32, fp_temp);
        else
            fputc(ch, fp_temp);
	}

    rename("temp.txt", argv[1]);

    fclose(fp_origin);
    fclose(fp_temp);

    fp_origin = NULL;
    fp_temp = NULL;

    return 0;
}
