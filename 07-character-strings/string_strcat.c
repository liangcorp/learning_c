#include <stdio.h>

int main()
{
    char str[50], dest[50];

    strcpy(src, "This is source");
    strcpy(dest, "This is destination");

    strncat(dest, src, 15);

    printf("Final destination string: [%s]", dest);

    return 0;
}