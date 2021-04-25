#include <stdio.h>

int array_sum(int array[], const int n)
{
    int sum = 0, *ptr;
    int * const array_end = array + n;

    for(ptr = array; ptr < array_end; ++ptr)
    {
        sum += *ptr;
    }

    return sum;
}

void main(void)
{
    int array_sum(int array[], const int n);
    int values[10] = {3, 7, -9, 3, 6, -1, 7, 9, 1, -5};

    printf("The sum is %i\n", array_sum(values, 10));
}
