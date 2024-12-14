#include <stdio.h>

#define BYTE_MASK 0xff

int main()
{
    /*
        The code uses right-shift operator to move the 8-bit color
        value to the low-order byte

        then uses the mask technique to assign the low-order byte
        to the desired variable

        the long color variable can be used to calculate three
        other colors (without using additional variables)
    */

    unsigned long color = 0x002a162f;
    unsigned char blue, green, red;

    red = color & BYTE_MASK;
    green = (color >> 8) & BYTE_MASK;
    blue = (color >> 16) & BYTE_MASK;

    return 0;
}
