#include <stdio.h>

static double var2;    // global variable only accessible in this file

double var3;    //  global variable accessible within entire program

void foo()
{
    auto int var = 0;    // int variable with block scope and temporory storage

    static float var4;    // local variable with permanent storage
}

//  a functoin that's only accessible within this file
static int get_value()
{
    return 1;
}

int main()
{
    register int var5;
    return 0;
}
