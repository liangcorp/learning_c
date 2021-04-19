#include <stdio.h>

int main(void)
{
    int number = 0;
    int position = 0;
    int mask = 1;
    int bit = 0;

    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Enter a position: ");
    scanf("%d", &position);

    mask = mask << position;

    bit = (number & mask) >> position;

    printf("The %d bit is set to %d\n", position, bit);


    printf("The number before setting %d bit: %d\n", position, number);

    number = number | mask;
    printf("The number after setting %d bit: %d\n", position, number);

    return 0;
}