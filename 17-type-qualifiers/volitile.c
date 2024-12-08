#include <stdio.h>

int main()
{
    /*
       Compilter optimizer must be careful to
       reload the variable every time it is used
       instead of holding a copy in register.

       I.e., no CPU register caching

       Three type of variable should use volatile
       - memory-mapped peripheral registers
       - global variables (non stack variables) modified
       by an interrupt service routine
       - global variables accessed by multiple tasks within
       a multi-threaded application

    */

    volatile int d = 0;

    printf("%d\n", d);

    return 0;
}
