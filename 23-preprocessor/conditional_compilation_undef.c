#include <stdio.h>

#define LINUX 1
#undef LINUX

int main()
{
#ifdef LINUX
    printf("Linux\n");
#endif

    return 0;
}
