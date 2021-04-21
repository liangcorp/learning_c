#include <stdio.h>

union number
{
    int x;
    double y;
};

void foo(union number n)
{
    union number x = n;
}

int main(void)
{
    union number value;

    value.x = 100;
    printf("Value of integer x: %d\n", value.x);
    printf("value of double y: %f\n", value.y);

    value.y = 43.23;
    printf("value of integer x: %d\n", value.x);
    printf("value of double y: %f\n", value.y);

    return 0;
}