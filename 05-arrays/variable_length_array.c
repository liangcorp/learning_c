#include <stdio.h>

int main()
{
    //  added in C99
    int n = 5;
    int m = 8;

    float f1[n];    //  VLA not allowed before C99
    float f2[m];    //  VLA not allowed before C99

    float a1[-4];   //  Not allowed
    float a2[0];   //  Not allowed
    float a3[2.5];   //  Not allowed

    float a4[(int)2.5];   //  allowed
    float a5[5 * 2 + 1];   //  allowed
    float a6[sizeof(int) + 1];   //  allowed

    return 0;
}

