#include <stdio.h>

int main()
{
	int i = 0;
	int sum = 0;
	int array_len = 0;

	printf("Enter the number of elements: ");
	scanf("%d", &array_len);

	int a[array_len];

	for (i = 0; i < array_len; i++) {
		printf("Enter element %d: ", i + 1);
		scanf("%d", a + i);
		sum += *(a + i);
	}

	printf("Sum of all elements = %d\n", sum);

	return 0;
}
