#include <stdio.h>

int sum_of_range(int);

int main(void)
{
    int n1 = 0;
    int sum = 0;

    printf("\n\n Recursion: calculate the sum of numbers ");
    printf("from 1 to n: \n");

    printf("-------------------------------------------\n");

    printf("Input the last number of the range string from 1: ");
    scanf("%d", &n1);

    sum_of_range(n1);

    return 0;
}

int sum_of_range(int n)
{
    int result = 0;

    if (n == 1)
        return 1;
    else
        result = n + sum_of_range(n - 1);

    return result;
}