#include <stdio.h>

int main()
{
    /*
       Undefined behaviour:
        - Shifting too much left
        - Shifting signed int to the right
        - Shifting a nagive amount
    */

    int i = 1;          // 0000 0000 0000 0000 0000 0000 0000 00001

    int w1 = 3;         // 0000 0000 0000 0000 0000 0000 0000 00011

    int result = 0;

    result = w1 << 1;   // 0000 0000 0000 0000 0000 0000 0000 00110
    //  6

    printf("%d\n", result);

    unsigned int w2 = 4151832098    // 1111 0111 0111 0111 1110 1110 0010 0010
    result = w2 >> 1                // 0111 1011 1011 1011 1111 0111 0001 0001 = 2075916049

    printf("%d\n", result);

    signed int w3 = 138;    //  1000 1010   danger of signed
    result = w3 >> 2;       //    0010 0010
                            // or 1110 0010 on some systems
    return 0;
}
