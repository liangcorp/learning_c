#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	double width = atoi(argv[1]);
	double height = atoi(argv[2]);
	double perimeter = 0.0;
	double area = 0.0;

	perimeter = 2.0 * (height + width);

	area = height * width;

	printf("Height: %.2f\n", height);
	printf("Width: %.2f\n", width);
	printf("Perimeter: %.2f\n", perimeter);
	printf("Area: %.2f\n", area);
}
