#include <stdio.h>
#include <math.h>

#define NDEBUG  // turn off assert
#undef NDEBUG   // turn on assert
#include <assert.h>

int main()
{
    double x, y, z;

    puts("Enter a pair of numbers (0 0 to quite): ");
    while (scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0)) {
        z = x * x - y * y;
        assert(z >= 0);
        printf("answer is %f\n", sqrt(z));
        puts("Next pair of numbers: ");
    }
    puts("Done");

    return 0;
}
