#include <stdio.h>

/* Remove printf function by poisoning it */
#pragma GCC poison printf

int main(void)
{
    print("Hello\n");
    return 0;
}
