/*
   Less used but potentially most useful
*/

#include <stdio.h>
#include <float.h>
#include <limits.h>

#if(INT_MAX != 32767)
#error *** This file only works with 16-bit int.
#endif

#if __STDC_VERSION__ != 20112L   // should fail if compiler used is an older
                                // standard and success when it uses C11
#error Not C11
#endif

int main()
{

    printf("Hello world\n");

    return 0;
}
