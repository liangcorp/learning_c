#include <stdio.h>
#include <malloc.h>
#include <string.h>

void foo(char **ptr)
{
    *ptr = malloc(255);
    strcpy(*ptr, "Hello World");
}

int main()
{
    char *ptr = NULL;

    foo(&ptr);
    printf("%s\n", ptr);

    free(ptr);
    ptr = NULL;

    return 0;
}
