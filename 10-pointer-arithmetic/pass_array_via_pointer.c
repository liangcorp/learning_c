#include <stdio.h>

#define SIZE 10

//  Pass via array value
int array_sum(int array[], const int n)
{
    int sum = 0;
    int *ptr;
    int *const array_end = array + n;

    for (ptr = array; ptr < array_end; ptr++)
        sum += *ptr;

    return sum;
}

//  Pass via array pointer
int array_sum(int *array, const int n)
{
    int sum = 0;
    int *const array_end = array + n;

    for ( ; array < array_end; array++)
        sum += *array;

    return sum;
}

int main()
{
    int values[SIZE] = { 3, 7, -9, 3, 6, -1, 7, 9, 1, -5 };
    printf("The sum is %i\n", array_sum(values, SIZE));

    return 0;
}
