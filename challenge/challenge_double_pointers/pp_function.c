#include <stdio.h>
#include <malloc.h>

void allocate_memory(int *ptr)
{
    ptr = (int *) malloc(sizeof(int));
}

void allocate_memory_pp(int **ptr)
{
    *ptr = (int *) malloc(sizeof(int));
}

int main(void)
{
    int *i = NULL;

    allocate_memory_pp(&i);

    *i = 10;
    printf("Integer **i = %d\n", *i);

    free(i);

    return 0;
}
