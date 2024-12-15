#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	int sum;
	int data[] = { 0, 0 };

	while (i < 100)
		sum += data[i], ++i;

	int x = 0;
	int y = 0;
	int z = 0;

	x = (y = 3, (z = ++y + 2) + 5);

	printf("%d\n", x);

	for (i = 0, j = 100; i != 10; ++i, j -= 10)
		;

	printf("Jason"), printf("Fedin"), printf("Done");

	int houseprice;
	houseprice = 249, 500;
	//  houseprice = 249;
	//  500;
	houseprice = (249, 500);
	//  housepirce = 500;

	return 0;
}
