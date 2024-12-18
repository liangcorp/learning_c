#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main()
{
    FILE *fp = NULL;
    char buff[255];
    char words[MAX];

    if ((fp = fopen("data.txt", "r")) == NULL) {
        fprintf(stderr, "ERROR: unable to open file\n");
        return 1;
    }

    while(fscanf(fp, "%s", buff) != EOF) {
        printf("%s\n", buff);
    }

    fclose(fp);
    fp = NULL;

    if ((fp = fopen("data.txt", "a+")) == NULL) {
        fprintf(stderr, "ERROR: unable to open file\n");
        return 1;
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");

    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%s\n", words);

    puts("File contents: ");
    rewind(fp); /* go back to the beginning of file */

    while(fscanf(fp, "%s", words) == 1)
        puts(words);

    puts("Done!");

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
