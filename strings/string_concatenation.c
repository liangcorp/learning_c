#include <stdio.h>
#include <string.h>

int main()
{
    char src[50];
    char dest[50];

    strcpy(src, "This is source");
    strcpy(dest, "This is destination");

    strncat(dest, src, 15);

    printf("Final destination string: |%s|\n", dest);

    return 0;
}