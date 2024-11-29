#include <stdio.h>

void swap_via_value(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap_via_reference(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int x = 100;
    int y = 200;

    printf("Before swap x: %d, y: %d\n", x, y);

    swap_via_value(x, y);
    printf("After swap by value x: %d, y: %d\n", x, y);

    swap_via_reference(&x, &y);
    printf("After swap by reference x: %d, y: %d\n", x, y);

    return 0;
}
