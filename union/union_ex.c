#include <stdio.h>

union car
{
    int i_value;
    float f_value;
    char c_value[40];
} car4, *car5;

int main(void)
{
    union car car1, car2, *car3;
    printf("Memory size occupied by car: %zu\n", sizeof(car1));

    return 0;
}
