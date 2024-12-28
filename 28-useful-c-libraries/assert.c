#include <stdio.h>
#include <assert.h>

int main(void)
{
    int x;
    int y = 5;

    for (x = 0; x < 20; x++) {
        printf("x = %d, y = %d", x, y);
    }

    assert(x < y);

    return 0;
}
