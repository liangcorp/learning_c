#include <stdio.h>

struct date {
	int day;
	int month;
	int year;
};

int main()
{
	{
		//  Sample 1
		struct date my_holidays[10];

		my_holidays[1].day = 23;
		my_holidays[1].month = 12;
		my_holidays[1].year = 2024;
	}

	{
		//  Sample 2 - set first three holidays
		struct date my_holidays[10] = { { 20, 12, 2024 },
						{ 21, 12, 2024 },
						{ 22, 12, 2024 } };
	}

	{
		//  Sample 3 - same as 2 but assign specific element
		struct date my_holidays[10] = { [2] = { 22, 12, 2024 } };
	}

	{
		//  Sample 4 - only assigned month and date
		struct date my_holidays[10] = { [1].month = 12, [1].day = 30 };
	}

	printf("\n");
	return 0;
}
