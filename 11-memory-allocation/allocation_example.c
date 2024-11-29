#include <stdio.h>

int main()
{
    char *str;

    //  Initial memory allocation
    str = (char *)malloc(15 * sizeof(char));
    strcpy(str, "jason");
    printf("String = %s, Address = %u\n", str, str);

    //  Reallocating memory
    str = (char *)realloc(str, 25 * sizeof(char));
    strcat(str, ".com");
    printf("String = %s, Address = %u\n", str, str);

    free(str);
    str = NULL;

    return 0;
}
