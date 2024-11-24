#include <stdio.h>

int main()
{
    unsigned int a = 60;    //  0000 0000 0000 0000 0000 0000 0011 1100
    unsigned int b = 13;    //  0000 0000 0000 0000 0000 0000 0000 1101

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("a & b = %d\n", a & b);  //  0000 1100
    printf("a | b = %d\n", a | b);  //  0011 1101
    printf("a ^ b = %d\n", a ^ b);  //  0011 0001
    printf("~a = %d\n", ~a);        //  1100 0011
    printf("b >> 2 = %d\n", b >> 2);    //  0000 1111
    printf("b << 2 = %d\n", b << 2);    //  1111 0000

    return 0;
}
