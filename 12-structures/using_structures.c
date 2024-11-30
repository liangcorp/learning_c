#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};

int main()
{
	struct date today;

	today.month = 9;
	today.day = 25;
	today.year = 2015;

	struct date another = { 10, 30, 2016 };
	struct date one = { .month = 10, .day = 30 };
	struct date two = { .year = 2016 };

	//  Compound literal after C11
	today = (struct date){ 10, 30, 2016 };

	printf("Today's date is %i/%i/%.2i.\n", today.month, today.day,
	       today.year % 100);

	return 0;
}
