#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};

int main()
{
	struct date today, *date_ptr;

	date_ptr = &today;

	date_ptr->month = 9;
	date_ptr->day = 25;
	date_ptr->year = 2015;

	printf("Today's date is %i/%i/%.2i.\n", date_ptr->month, date_ptr->day,
	       date_ptr->year % 100);

	return 0;
}
