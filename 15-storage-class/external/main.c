#include <stdio.h>

int i = 5;

extern void foo(void);

int main()
{
    printf("%d\n", i);
    foo();
    printf("%d\n", i);

    return 0;
}
