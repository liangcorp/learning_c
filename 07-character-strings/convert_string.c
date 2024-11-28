#include <stdio.h>

int main()
{
    double value = 0.0;
    char string[] = "3.5, 2.5 1.26";

    char *pstr = str;
    char *ptr = NULL;

    while (true) {
        value = strtod(str, &ptr);

        if (pstr == ptr)
            break;
        else
            pstr = ptr;
    }
    return 0;
}
