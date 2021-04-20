#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int adding_numbers(int n_how_many, ...);

int main(void)
{
    printf("\n\n Variadic functions: \n\n");

    printf("\n 10 + 20 = %d ", adding_numbers(2, 10, 20));

    printf("\n 10 + 20 + 30 = %d", adding_numbers(3, 10, 20, 30));

    printf("\n 10 + 20 + 30 + 40 = %d", 
                        adding_numbers(4, 10, 20, 30, 40));

    printf("\n\n");

    return 0;
}

int adding_number(int n_how_many, ...)
{
    int n_sum = 0;

    va_list int_argument_pointer;
    va_start(int_argument_pointer, n_how_many);

    for (int i = 0; i < n_how_many; i++)
    {
        n_sum += va_arg(int_argument_pointer, int);
    }

    va_end(int_argument_pointer);

    return n_sum;
}