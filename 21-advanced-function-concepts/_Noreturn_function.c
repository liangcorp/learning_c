/*
   Compiler hint

   Inform the user and the compiler that a particular function will not
   return control to the calling program when it completes execution
    - informing user helps to prevent misuse of the function
    - informing the compiler may enable it to make some code optimizations
*/

#include <stdio.h>

_Noreturn void f()
{
    abort();
}

_Noreturn void g(int i)
{
    // causes undefined behavior if i <= 0
    if (i > 0)
        abort();
}

int main()
{
    f();
    return 0;
}
