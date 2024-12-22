#include <stdio.h>

#define PI 3.14

#define CIRCLE_AREA(x) ((PI) * (x) * (x))

#define Warning(...) fprintf(stderr, __VA_ARGS__)

#define MISC(x) (puts("incrementing"), (x)++)

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int area = CIRCLE_AREA(4);

    // int area = ((3.14) * 4) * (4));
    int i;

    printf("Area is %d\n", area);

    Warning("%s: this program is here\n", "Jason");

    return 0;
}
