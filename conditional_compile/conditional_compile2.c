#include <stdio.h>

#define MYDEF 5
// #define MYOTHERDEF 2

int main(void)
{

    #if MYDEF == 5 && MYOTHERDEF == 2
        printf("Hello");
    #endif

    return 0;
}
