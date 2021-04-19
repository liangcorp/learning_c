#include <stdio.h>

long long decimal_to_binary(int n)
{
    int remainder = 0;
    int i = 1;
    long long binary_num = 0;

    while (n != 0)
    {
        remainder = n % 2;
        n = n / 2;
        binary_num += remainder * i;
        i *= 10;
    }

    return binary_num;
}

int main(void)
{
    unsigned int n1 = 0;
    unsigned int n2 = 0;

    printf("Enter two numbers: ");
    scanf("%d", &n1);
    scanf("%d", &n2);

    printf("n1 in binary form: %lld\n", decimal_to_binary(n1));
    printf("n2 in binary form: %lld\n", decimal_to_binary(n2));

    printf("Result of number 1 after ~ is: %lld\n", decimal_to_binary(~n1));
    printf("Result of number 2 after ~ is: %lld\n", decimal_to_binary(~n2));

    printf("Result of n1 & n2: %lld\n", decimal_to_binary(n1 & n2));
    printf("Result of n1 | n2: %lld\n", decimal_to_binary(n1 | n2));
    printf("Result of n1 ^ n2: %lld\n", decimal_to_binary(n1 ^ n2));

    printf("n1 >> 1: %lld\n", decimal_to_binary(n1 >> 1));
    printf("n2 << 1: %lld\n", decimal_to_binary(n2 << 1));

    return 0;
}