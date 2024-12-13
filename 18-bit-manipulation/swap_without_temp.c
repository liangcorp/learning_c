#include <stdio.h>

int main()
{
    short int w1 = 147;
    short int w2 = 61;

    w1 ^= w2;
    w2 ^= w1;
    w1 ^= w2;

    return 0;
}
