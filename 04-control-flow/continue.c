#include <stdio.h>

int main()
{
	enum Day {
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday,
		Sunday
	};

	for (enum Day day = Monday; day <= Sunday; day++)
		continue;

	printf("It's not Wednesday!\n");

	return 0;
}
