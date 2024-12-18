#include <stdio.h>

int main()
{
    char string[100];
    int n = 55;
    int a = 10;
    int b = 20;
    int c = 0;

    c = a + b;

    sprintf(string, "Hello, this is the number: %d", n);
    puts(string);

    sprintf(string, "Sum of %d and %d is %d", a, b, c);
    puts(string);

    return 0;
}
