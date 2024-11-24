#include <stdio.h>

int main()
{
    int integerVar = 100;
    float floatVar = 331.79;
    double doubleVar = 8.44e+11;
    char charVar = 'W';

    _Bool boolVar = 0;

    printf("integerVar = %i\n", integerVar);
    printf("floatVar = %f\n", floatVar);
    printf("doubleVar = %e\n", doubleVar);
    printf("doubleVar = %g\n", doubleVar);
    printf("charVar = %c\n", charVar);

    printf("boolVar = %d\n", boolVar);


    // precision width specifier
    float x = 3.99992323232323;
    printf("%.2f", x);

    return 0;
}
