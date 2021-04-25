#include <stdio.h>

int get_sum(int n)
{
    int sum = 0;

    if (n > 0)
        sum = n + get_sum(n - 1);

    return sum;
}

int main(void)
{
    int n = 0;
    printf("Input the last number of the range starting from 1: ");
    scanf("%d", &n);

    printf("The sum of numbers from 1 to %d is %d\n", n, get_sum(n));

    return 0;
}
