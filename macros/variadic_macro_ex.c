#include <stdio.h>

#define Warning(format, ...) fprintf(format, stderr, __VA_ARGS__)

int main(void)
{
    Warning("%s: this program is here\n", "Jason");

    return 0;
}

