#include <stdio.h>

#define PI 3.14
#define CIRCLE_AREA(x) ((PI) * (x) * (x))

int main(void)
{
    int c = 5;
    int area = CIRCLE_AREA(c + 2);

    printf("Area is %d\n", area);

    return 0;
}
