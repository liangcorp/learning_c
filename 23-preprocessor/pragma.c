/*
   pragma - pragmatic
   the #pragma directive lets you place compiler instructions
   in your source code

   - control the amount of memory set aside for automatic variables
   - to set the strictness of error checking
   - to enable nonstandard language features
*/

#pragma GCC dependency "/usr/include/time.h" rerun fixincludes

#pragma GCC poison sprintf fprintf

#pragma GCC system_header   // rest of the current include file as a system header
                            // GCC gives system header special treatment

#pragma once        // header file containing this directive is include only once

#pragma GCC warning "message"   // cause the preprocessing to issue a warning diagnostic with the text "message"
#pragma GCC error "message"     // cause the preprocessing to issue a error diagnostic with the text "message"
#pragma GCC message "message"   // cause the preprocessing to issue a message diagnostic with the text "message"

#include <stdio.h>

int main()
{
    sprintf(stdout, "Hello, world!\n");

    return 0;
}
