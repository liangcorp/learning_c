#include <stdio.h>

typedef int* i_pointer;

int main(void)
{
    i_pointer p;    // same as int *p
    i_pointer a, *b;    // same as int *a **b

    i_pointer my_array[10]; // same as int* my_array[10]

    return 0;
}