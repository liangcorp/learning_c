#include <stdio.h>

int main()
{
    float width = 1.0;
    float height = 2.0;
    float perimeter = (width + height) * 2;
    float area = width * height;

    printf("Rectangle width: %.2f\n", width);
    printf("Rectangle height: %.2f\n", height);
    printf("Rectangle perimeter: %.2f\n", perimeter);
    printf("Rectangle area: %.2f\n", area);

    return 0;
}
