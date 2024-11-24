#include <stdio.h>

int main()
{
    double width = 1.0;
    double height = 2.0;
    double perimeter = (width + height) * 2;
    double area = width * height;

    printf("Rectangle width: %.2lf\n", width);
    printf("Rectangle height: %.2lf\n", height);
    printf("Rectangle perimeter: %.2lf\n", perimeter);
    printf("Rectangle area: %.2lf\n", area);

    return 0;
}
