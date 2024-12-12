#include <stdio.h>
#include <math.h>

long long convert_decimal_to_binary(int n)
{
    long long binary_number = 0;
    int remainder;
    int i = 1;

    while (n != 0) {
        remainder = n % 2;
        n = n / 2;
        binary_number += remainder * i;
        i = i * 10;
    }

    return binary_number;
}

int convert_binary_to_decimal(long long n)
{
	int decimal_num = 0;
	int i = 0;
	int remainder = 0;

	while (n != 0) {
        remainder = n % 10;
        n = n / 10;
        decimal_num += remainder * pow(2, i);
        i++;
    }

    return decimal_num;
}

int main()
{
	long long n;
    int m;
	int decimal_result;
    long long binary_result;

	printf("Enter a binary number: ");
	scanf("%lld", &n);

	decimal_result = convert_binary_to_decimal(n);
	printf("%lld in binary = %d in decimal", n, decimal_result);

	printf("Enter a decimal number: ");
	scanf("%d", &m);

	binary_result = convert_decimal_to_binary(m);
	printf("%d in decimal = %lld in binary", m, binary_result);

	return 0;
}
