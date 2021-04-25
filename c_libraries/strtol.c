#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[30] = "2030300 This is test";
    char *ptr = NULL;
    long ret = 0;

    ret = strtol(str, &ptr, 10);
    printf("The number (unsigned long integer) is %ld\n", ret);
    printf("String part is |%s|", ptr);

    return 0;
}