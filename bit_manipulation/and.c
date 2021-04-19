#include <stdio.h>

int main(void)
{
    short int w1 = 25;
    short int w2 = 77;
    short int w3 = 0;

    w3 = w1 & w2;
    printf("%d\n", w3);

    w3 = w1 | w2;
    printf("%d\n", w3);

    w3 = w1 ^ w2;
    printf("%d\n", w3);
    
    /* variable swap using XOR */
    w1 ^= w2;
    w2 ^= w1;
    w1 ^= w2;


    signed int w = 154;
    signed int result = 0;

    result = ~(w);
    printf("%d\n", result);


    return 0;
}