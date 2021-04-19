#include <stdio.h>

void multiply_two_numbers(int x, int y)
{
    int result = x * y;
    printf("The product of %d mutiplied by %y is: %d\n", x, y, result);
}

int main(void)
{
    multiply_two_numbers(10, 20);
    multiply_two_numbers(20, 30);
    multiply_two_numbers(50, 2);

    return 0;
}