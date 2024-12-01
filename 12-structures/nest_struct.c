#include <stdio.h>

// Time is within scope of Date
struct Date {
    struct Time {
        int hour;
        int miniute;
        int seconds;
    }
    int day;
    int month;
    int year;
};

//  Time is outside the scope of Date
struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Date {
    int day;
    int month;
    int year;
}

struct DateAndTime {
    struct date sdate;
    struct time stime;
}

int main()
{
    {
        struct DateAndTime event = { { 2, 1, 2015 }, { 3, 30, 0 } };
    }

    {
        struct DateAndTime event = { { .month = 2, .day = 1, .year = 2015 },
            {.hour = 3, .month = 30, .seconds = 0 }
        };
    }

    {
        struct DateAndTime events[100];
        events[0].stime.hour = 12;
        events[0].stime.minutes = 0;
        events[0].stime.seconds = 0;
    }

    printf("\n");

    return 0;
}
