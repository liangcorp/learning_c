#include <stdio.h>

long long decial_to_binary(int n)
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

int main()
{
    int num1, num2;

    printf("Enter 2 numbers: ");
    scanf("%d", &num1);
    scanf("%d", &num2);

    printf("Complements: %lld\n", decial_to_binary(~num1));
    printf("Result of AND operator: %lld\n", decial_to_binary(num1 & num2));
    printf("Result of OR operator: %lld\n", decial_to_binary(num1 | num2));
    printf("Result of XOR operator: %lld\n", decial_to_binary(num1 ^ num2));
    printf("Right shift 2: %lld\n", decial_to_binary(num1 >> 2));
    printf("Left shift 2: %lld\n", decial_to_binary(num1 << 2));

    return 0;
}
