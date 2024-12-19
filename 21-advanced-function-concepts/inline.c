#include <stdio.h>

/*
   Compiler hint
   place a copy of the function code where it's called
*/

inline static void foo()
{
    printf("Hello, World!\n");
}

int main()
{
    foo();

    foo();

    return 0;
}
