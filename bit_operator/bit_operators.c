#include <stdio.h>
int main()
{
    unsigned int a = 60;    // 0000 0000 0000 0000 0000 0000 0011 1100
    unsigned int b = 13;    // 0000 0000 0000 0000 0000 0000 0000 1101
    printf("a is %d,\nb is %d\n", a, b);
    
    int result = 0;

    result = a & b;         // 0000 0000 0000 0000 0000 0000 0000 1100    
    printf("Result of AND operator: %d\n", result);

    result = a | b;         // 0000 0000 0000 0000 0000 0000 0011 1101
    printf("Result of OR operator is: %d\n", result);

    result = ~a;            // 0000 0000 0000 0000 0000 0000 1100 0011
    printf("Result of NOT operator on 'a' is: %d\n", result);

    result = a << 2;        // 0000 0000 0000 0000 0000 0000 1111 0000
    printf("Result of shifting 'a' left for 2 bits: %d\n", result);

    result = a << 4;        // 0000 0000 0000 0000 0000 0011 1100 0000
    printf("Result of shifting 'a' left for 4 bits: %d\n", result);

    /* compilation error */
    // result = a << 34;
    // printf("Result of shifting 'a' to the left for 34 bits %d\n", result);

    result = a >> 4;        // 0000 0000 0000 0000 0000 0000 0000 0011 
    printf("Result of shifting 'a' right for 4 bits: %d\n", result);

    return 0;
}