#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str1[10], str2[10], str3[10], str4[10], str5[10];
    int year;
    FILE *fp;

    fp = fopen("myfile.txt", "w+");

    if (fp != NULL)
        fputs("Hello how are you 2021", fp);

    rewind(fp);

    fscanf(fp, "%s %s %s %s%s %d", str1, str2, str3, str4, &year);
    printf("Read String1 |%s|\n", str1);
    printf("Read String2 |%s|\n", str2);
    printf("Read String3 |%s|\n", str3);
    printf("Read Integer |%s|\n", str4);
    printf("Read Integer |%d|\n", year);

    fclose(fp);
    fp = NULL;
    return 0;
}
