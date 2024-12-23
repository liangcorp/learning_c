#include <stdio.h>

#ifdef UNIX
#define DATADIR "/uxn1/data"
#else
#define DATADIR "/usr/data"
#endif

int main()
{
    printf("%s\n", DATADIR);

    return 0;
}
