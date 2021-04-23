#include <stdio.h>
#include <malloc.h>

void foo (int* ptr)
{
    int a = 5;
    ptr = &a;   /* NOTE: *ptr = a; will change the value in main */
}

void foo_doub_ptr(int** ptr)
{
    int a = 5;
    *ptr = &a;
}

int main(void)
{
    int *ptr = NULL;
    int **doub_ptr = NULL;

    ptr = (int *) malloc(sizeof(int));
    *doub_ptr = (int *) malloc(sizeof(int));

    *ptr = 10;
    **doub_ptr = 10;

    foo(ptr);
    printf("%d\n", *ptr);

    foo_doub_ptr(doub_ptr); /* Same of below */
    foo_doub_ptr(&ptr);

    printf("%d\n", *ptr);
    printf("%d\n", **doub_ptr);

    return 0;
}