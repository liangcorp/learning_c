#include <stdio.h>

int main(void)
{
    int num, position, new_num, bit_status;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter bit position: ");
    scanf("%d", &position);

    /* Right shift num, position times and perform bitwise AND with 1 */
    bit_status = (num >> position) & 1;
    printf("The %d bit is set to %d\n", position, bit_status);

    /* Left shift 1, n times and perform bitwise OR with num */
    new_num = ( 1 << position ) | num;
    printf("\nBit set successfully.\n\n");

    printf("Before: %d\n", num);
    printf("After: %d\n", new_num);

    return 0;
}
