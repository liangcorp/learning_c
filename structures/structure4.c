#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

int main(void)
{
    struct date today, *p_date;

    p_date = &today;

    p_date->year = 2012;
    p_date->month = 12;
    p_date->day = 30;

    return 0;
}
