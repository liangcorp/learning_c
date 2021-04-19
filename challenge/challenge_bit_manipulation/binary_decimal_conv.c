#include <stdio.h>
#include <math.h>

int binary_to_decimal(long long b_num)
{
    int d_num = 0;
    int i = 0;

    while (b_num != 0)
    {        
        d_num += (b_num % 10) * pow(2, i);
        printf("%d * 2^%d\n", b_num % 10, i);
        b_num = b_num / 10; //  move the binary to the right by 1 bit
        i++;
    }

    return d_num;
}

long long decimal_to_binary(int d_num)
{
    long long b_num = 0;
    int quotient = d_num;
    int remainder = 0;
    int decimal_pos = 1;

    while (quotient != 0)
    {
        quotient = d_num / 2;
        remainder = d_num % 2;
        d_num = quotient;

        b_num += remainder * decimal_pos;
        decimal_pos *= 10;        
    }

    return b_num;
}

int main(void)
{
    long long b_num = 0;
    int d_num = 0;

    printf("Enter a binary number: ");
    scanf("%lld", &b_num);
    printf("Decimal number: %d\n", binary_to_decimal(b_num));

    printf("Enter a decimal number: ");
    scanf("%d", &d_num);
    printf("Binary number is %lld\n", decimal_to_binary(d_num));

    return 0;
}