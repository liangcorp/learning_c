#include <stdio.h>

int main()
{
    /*
       Local variable only
       It's a compiler hint
       Subject to compiler and handware implementation restrictions
    */

    /*
       a processor register (CPU register) is one of a small
       set of data holding places that are part of the computer
       processor
        - a register may hold an instructure, a storage address,
        or any kind of data
    */

    /*
       make use of the register variable to be much faster than
       in memory
    */

    register int x; //  register variable
                    //  No memory address

    for (x = 0; x < 15; x++)
    {
        printf("%d\n", x);
    }

    return 0;
}
