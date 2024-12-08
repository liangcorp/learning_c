#include <stdio.h>

struct point {
    int x;
    int y;
};

int main()
{
    int i;

    int a[6] = { [4] = 29, [2] = 15 };

    //  same as
    //  int a[6] = { 0, 0, 15, 0, 29, 0 };

    int c[] = { [0 ... 9] = 1, [10 ... 99] = 2, [100] = 3 };

    for (i = 0; i < 20; i++)
        printf("%d ", a[i]);

    struct point p1 = { .y = 2, .x = 3};
    struct point p2 = { y: 2, x: 3};
    struct point p3 = { 2, 3 }; // x = 2, y = 3

    struct point pts[5] = { [2].y = 5, [2].x = 6, [0].x = 2 };

    return 0;
}
