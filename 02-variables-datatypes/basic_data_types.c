#include <stdio.h>
#include <stdbool.h>    //  C99

int main() {

    int x = 1;
    float y = 1.0;
    double y2 = 10000.0e+11;

    //  C89
    _Bool b = 0;  // false
    b = 1;  // true

    //  C99
    bool my_bool = true;
    my_bool = false;

    char c = 'a';

    // All floating constants are taken
    // as double values by the C compiler
    const float i = 1.0;

    // To explicilyt express a float constant:
    const float j = 1.0F;


    return 0;
}
