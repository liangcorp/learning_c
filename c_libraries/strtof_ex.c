#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a[] = "365.25 7.0", *end;
    float value = strtof(a, &end);
    float value2 = strof(end, NULL);

    printf("Value = %f:%f\n", value, value2);

    return 0;
}