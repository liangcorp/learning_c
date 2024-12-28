#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[10] = "100";
    char b[10] = "100.0";

    int value = atoi(a);    // to int
    // atol() to long
    printf("Value = %d\n", value);

    float value2 = atof(b); // to float
    printf("Value2 = %f\n", value2);

    char *end;

    char c[] = "123.456xyz";
    double value3 = 0;
    value3 = strtod(c, &end);
    printf("Value3 = %lf\n", value3);

    char d[] = "365.25 7.0";
    float value4 = strtof(a, &end);
    float value5 = strtof(end, NULL);

    printf("Value = %f:%f\n", value4, value5);

    char str[30] = "2030300 This is test";

    char *ptr;
    long ret;
    ret = strtol(str, &ptr, 10);
    printf("The number (unsighed long integer) is %ld\n", ret);
    printf("String part is |%s|", ptr);

    return 0;
}
