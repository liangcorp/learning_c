#include <stdio.h>

int main()
{
    /*
       Any variable defined in a function
       is automatically assumed auto by
       the C compiler
    */

    /*
       Imcompatible with C++

       maybe useful to overide other storage
       class declaration. E.g., "extern"

       or as a "DO NOT CHANGE" warning for
       other developers
    */

    auto int i;

    return 0;
}
