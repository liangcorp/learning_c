#include <stdio.h>

struct point
{
    int x;
    int y;
};

int main(void)
{
    struct point p = { .y = 2, .x = 3 };
    struct point p = { y: 2, x: 3 };
    struct point p = { 2, 3 };
    
    return 0;
}