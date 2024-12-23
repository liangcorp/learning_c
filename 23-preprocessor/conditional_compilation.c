#include <stdio.h>

/*
   - helps with hardware or software dependencies
   - switch on and off various statements
   - trace the flow of program
   - debuggin
*/

#define UNIX 1
// gcc -D UNIX main.c

#define JUST_CHECKING
#define LIMIT 4

int main()
{
    int i;
    int total = 0;

    for (i = 1; i <= LIMIT; i++) {
        total += 2 * i * i + 1;

#ifdef JUST_CHECKING
        printf("i = %d, running total =%d\n",i ,total);
#endif
    }

    printf("Grand total = %d\n", total);

    return 0;
}
