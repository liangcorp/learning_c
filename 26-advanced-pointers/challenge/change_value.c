#include <stdio.h>
#include <malloc.h>

void allocate_memory(int **ptr)
{
    *ptr = (int *)malloc(sizeof(int));
}

int main()
{
    int *ptr = NULL;
    allocate_memory(&ptr);

    *ptr = 20;
    printf("%d\n", *ptr);

    free(ptr);
    ptr = NULL;

    return 0;
}
