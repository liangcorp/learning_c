#include <stdio.h>

int main()
{
    printf("Comparing A and B: %d", strcmp("A", "B"));
    printf("Comparing A and A: %d", strcmp("A", "A"));
    printf("Comparing B and A: %d", strcmp("B", "A"));
    printf("Comparing C and A: %d", strcmp("C", "A"));

    //  Compare the first 2 letters
    strncmp("AA", "AAA", 2);    // True

    return 0;
}
