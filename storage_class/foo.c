#include <stdio.h>

struct date
{
    int year;
    int month;
    int day;
};	// Bad code practice. Use a header file.

extern int i;
extern struct date today;

void foo(void)
{
	i = 100;
	today.day = 30;
	
	printf("%d", today.day);
}
