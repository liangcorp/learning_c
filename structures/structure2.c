#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

struct time
{
    int hours;
    int minutes;
    int seconds;
};

struct time_and_date
{
    struct date s_date;
    struct time s_time;
};

int main(void)
{
    struct time_and_date event = 
                {{ .month = 2, .day = 1, .year = 2021},
                 { .hours = 3, .minutes = 30, .seconds = 0}
                };

    event.s_date.day = 30;
    event.s_time.hours = 12;

    return 0;
}