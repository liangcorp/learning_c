#include <stdio.h>
#include <stdlib.h>

void sign_off(void)
{
    puts("in sign_off...");
}

void too_bad(void)
{
    puts("in too bad...");
}

int main()
{
    int n = 0;

    atexit(sign_off);   // atexit()
    puts("Enter an integer: ");

    if (scanf("%d", &n) != 1) {
        puts("That's no integer!");
        atexit(too_bad);    // register the too_bad() function
        exit(EXIT_FAILURE);
    }

    return 0;
}
