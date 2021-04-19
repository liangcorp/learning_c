#include <stdio.h>

int main(void)
{
    char string[100];
    int a = 10;
    int b = 20;
    int c = 0;

    c = a + b;

    sprintf(string, "Hello, this is the number: %d", 55);
    puts(string);

    sprintf(string, "Sum of %d and %d is %d", a, b, c);
    puts(string);

    return 0;
}