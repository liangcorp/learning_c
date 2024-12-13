#include <stdio.h>

int main()
{
    /*
       Computer programming tasks that require bit
       manipulation include:
           - Low level device control
           - Error detectin
           - Correction algorithms
           - Data compression
           - Encryption algorithms
           - Optimization
    */

    short int w1 = 25;  //  00000000 00011001
    short int w2 = 77;  //  00000000 01001101
    short int w3 = 0;

    w3 = w1 & w2;       //  00000000 00001001
    printf("%d\n", w3);

    w3 = w1 | w2;       //  00000000 01011101
    printf("%d\n", w3);

    w3 = w1 ^ w2;       //  00000000 01010100
    printf("%d\n", w3);

    w3 = ~w1;           //  11111111 11100110
    printf("%d\n", w3);

    return 0;
}
