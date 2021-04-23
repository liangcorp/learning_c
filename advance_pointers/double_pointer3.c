#include <stdio.h>
#include <string.h>

void foo(char* ptr)
{
    /* 
        Won't work for main because ptr is not the original ptr
     */
    ptr = (char *) malloc(255 * sizeof(char)); 
    strcpy(ptr, "Hello World");
}

void foo_double_ptr(char** ptr)
{
    *ptr = (char *) malloc(255 * sizeof(char));
    strcpy(*ptr, "Hello World");
}


int main(void)
{
    char *ptr = NULL;
    foo(ptr);    /* Crashes the program due to memory not allocated */
    foo(&ptr);
    printf("%s\n", ptr);

    free(ptr);

    return 0;
}