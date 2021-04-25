#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *f = NULL;
    char ch[100];

    if ((f = fopen("myfile", "w+")) == NULL)
    {
        printf("Cannot open the file...\n");
        exit(1);
    }

    for (int i=0; i<10; i++)
    {
        // enter the strings with values in the file
        fprintf(f, "The count number is %d\n", i + 1);
    }

    fclose(f);

    if ((f = fopen("myfile", "r+")) == NULL)
    {
        printf("Cannot open the file...\n");
        exit(1);
    }

    printf("File content is--\n");
    printf("\n......................print the strings..........\n\n");

    while(!feof(f))
    {
        fgets(ch, 100, f);
        printf("%s", ch);
    }

    fclose(f);

    return 0;

}
