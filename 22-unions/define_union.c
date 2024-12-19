#include <stdio.h>

union car
{
	int i_value;
	float f_value;
	//  char c_value[40];   //  uncomment this and try
};

int main()
{
	union car car1;
	union car car2;
	union car *car3;

	printf("Memory size occupied by data: %zu", sizeof(car1));
	printf("Memory size occupied by data: %zu", sizeof(car2));
	printf("Memory size occupied by data: %zu", sizeof(*car3));

	return 0;
}
