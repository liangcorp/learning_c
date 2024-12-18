#include <stdio.h>
#include <stdlib.h>

/*
    useful in redirecting output to stderr
    fprintf(stderr, "Error message: %s", "some error!");
*/
int main()
{
    FILE *f = NULL;
    char ch[100];

    if ((f = fopen("data.txt", "w+")) == NULL) {
        puts("ERROR: Cannot open the file.");
        fprintf(stderr, "Error message: %s", "Cannot open the file.!");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        //  enter the strings with values in the file
        fprintf(f , "The count number is %d\n", i + 1);
    }

    fclose(f);
    f = NULL;

    if ((f = fopen("data.txt", "r+")) == NULL) {
        puts("ERROR: Cannot open the file.");
        fprintf(stderr, "Error message: %s", "Cannot open the file.!");
        return 1;
    }

    puts("File content is--");
    puts("........print the strings..........\n");

    while (!feof(f)) {
        fgets(ch, 100, f);
        printf("%s", ch);
    }

    fclose(f);
    f = NULL;

    return 0;
}
