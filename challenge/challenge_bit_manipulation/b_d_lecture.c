#include <stdio.h>
#include <math.h>

int convert_binary_to_decimal(long long n);
long long convert_decimal_to_binary(int n);

int main(void)
{
    long long b_num;
    int result = 0;
    int n = 0;

    printf("Enter a binary number: ");
    scanf("%d", &b_num);

    result = convert_binary_to_decimal(b_num);
    printf("%lld in binary = %d in decimal", b_num, result);

    printf("Enter a decimal number: ");
    scanf("%d", &n);
    b_num = convert_decimal_to_binary(n);


    return 0;
}

int convert_binary_to_decimal(long long n)
{
    int decimal_number = 0;
    int i = 0;
    int remainder = 0;

    while (n != 0)
    {
        remainder = n % 10;
        n = n / 10;
        decimal_number += remainder * pow(2, i);
        i++;
    }

    return decimal_number;
}

long long convert_decimal_to_binary(int n)
{
    long long b_num = 0;
    int remainder = 0;
    int i = 0;

    while (n != 0)
    {
        remainder = n % 2;
        n = n / 2;
        b_num += remainder * i;
        i *= 10;
    }

    return b_num;
}
