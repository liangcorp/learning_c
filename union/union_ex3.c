#include <stdio.h>

union mixed
{
    char c;
    float f;
    int i;
};

int main(void)
{
    union mixed x;
    union mixed y;

    x.c = 'j';

    y.f = 45.667;

    printf("Character = %c\n", x.c);

    return 0;
}
