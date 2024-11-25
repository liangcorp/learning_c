#include <stdio.h>

int main()
{
	enum Weekday {
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday,
		Sunday,
	};

	enum Weekday today = Monday;

	switch (today) {
	case Sunday:
		printf("Today is Sunday\n");
		break;
	case Monday:
		printf("Today is Monday\n");
		break;
	case Tuesday:
		printf("Today is Tuesday\n");
		break;
	default:
		printf("Not sure\n");
		break;
	}

	return 0;
}
