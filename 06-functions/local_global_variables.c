#include <stdio.h>

void my_function(void);

int my_global = 0;  // global variable

int main()
{
    int my_local_main = 0;  // local variable
    // can access my_global and my_local_main

    return 0;
}

void my_function()
{
    int x;  //  local variable
    // can access my_global and x,
    // cannot access my_local_main
}
