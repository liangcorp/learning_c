#include <stdio.h>

int main()
{
    unsigned int number;
    unsigned int n_th;
    unsigned int bit_status;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Enter nth bit (between 0 - 31): ");
    scanf("%d", &n_th);

    bit_status = (number >> n_th) & 1;
    printf("The %d bit is set to %d\n", n_th, bit_status);

    number |= 1 << n_th;
    printf("%d\n", number);

    return 0;
}
