#include <stdio.h>

int multiply_two_numbers(int x, int y)
{
    int result = x * y;
    return result;
}

int main(void)
{
    int result = 0;
    result = multiply_two_numbers(10, 20);

    printf("Result is %d\n", result);

    return 0;
}