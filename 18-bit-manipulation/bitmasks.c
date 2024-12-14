#include <stdio.h>

int main()
{
    int flags = 15; //  0000 1111
    int mask = 182; //  1011 0110

    //  Turning on bits using OR
    flags = flags | mask;   // 1011 1111

    //  Cleaning bits using AND and 1s complement
    flags = flags & ~MASK;  // 0000 1001

    //  Toggling bits using XOR
    flags = flags ^ mask;   // 1011 1001

    return 0;
}
