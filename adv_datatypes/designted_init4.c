#include <stdio.h>

struct point
{
    int x;
    int y;
};

int main(void)
{
    struct point pts[5] = {
        [2].y = 5,
        [2].x = 6,
        [0].x = 2
    };

    int i;
    for (i=0; i<5; i++)
        printf("%d %d\n", pts[i].x, pts[i].y);

    return 0;
}