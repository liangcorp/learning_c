#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void convert_case(FILE *f_ptr, const char *path);

int main(int argc, char const *argv[])
{
    FILE *f_ptr = NULL;
    char path[100];

    printf("Enter path of source file: ");
    scanf("%s", path);

    f_ptr = fopen(path, "r");

    if (f_ptr == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file\n");
        printf("Please check whether file exists and you have read");
        printf("privilege\n");
        exit(EXIT_FAILURE);
    }

    convert_case(f_ptr, path);

    return 0;
}

void convert_case(FILE *f_ptr, const char *path)
{
    FILE *dest = NULL;
    char ch = '\0';

    dest = fopen("temp.txt", "w");

    if (dest == NULL)
    {
        printf("Unable to create temporary file.\n");
        fclose(f_ptr);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(f_ptr)) != EOF)
    {
        /* 
         * If current character is uppercase then toggle
         * it to lowercase and vice versa.
         */
        if (isupper(ch))
            ch = tolower(ch);
        else if (islower(ch))
            ch = toupper(ch);
        
        fputc(ch, dest);
    }

    fclose(f_ptr);
    fclose(dest);
    remove(path);
    rename("temp.txt", path);
}