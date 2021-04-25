#include <stdio.h>

struct time
{
    struct date
    {
        int day;
        int month;
        int year;
    } dob;

    int hour;
    int minutes;
    int seconds
};

int main(void)
{
    struct time event;

    event.dob.year = 2021;
    event.hour = 12;

    return 0;
}
