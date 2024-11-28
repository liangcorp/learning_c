#include <stdio.h>

int main(void)
{
    int number = 0;
    int *p_number = NULL;

    number = 10;
    printf("number's address: %p\n", &number);
    printf("number's value: %d\n\n", number);

    p_number = &number;

    printf("p_number's address: %p\n", (void*)&p_number);   // The address
    printf("p_number's size: %zd bytes\n", sizeof(p_number));   // The size
    printf("p_number's value: %p\n", p_number);     //  The value
    printf("value pointed to: %d\n", *p_number);    // value at address

    return 0;
}
