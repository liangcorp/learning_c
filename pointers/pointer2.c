#include <stdio.h>

int main(void)
{
    int number = 0;         // A variable of type int initialized to 0
    int *p_number = NULL;   // A pointer that can point to type int

    number = 10;
    printf("number's address: %p\n", &number);      // Output the address
    printf("number's value: %d\n\n", number);       // Output the value

    p_number = &number;         // Store the address of number in p_number

    printf("p_number's address: %p\n", (void*)&p_number);  // Output the address
    printf("p_number's size: %zd bytes\n", sizeof(p_number)); // Output the size
    printf("p_number's value: %p\n", p_number);         // Output the value (an address)
    printf("value pointed to: %d\n", *p_number);        // Value at the address

    return 0;
}