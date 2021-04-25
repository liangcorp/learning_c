/*
    Author: Chen Liang
    Description: Write a program to compute the number
                    of seconds passwd since the beginning
                    of the current month. Use the following:
                    - localtime()
                    - difftime()
                    - mktime()
    Date: 25th Apr 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int main(void)
{
    double time_diff = 0;

    time_t today = time(NULL);
    time_t current_time_sec;
    time_t begin_month_sec;

    struct tm *current_time;
    struct tm begin_month;

    current_time = localtime(&today);

    begin_month = *current_time;

    begin_month.tm_sec = 0;
    begin_month.tm_min = 0;
    begin_month.tm_hour = 0;
    begin_month.tm_mday = 1;

    current_time_sec = mktime(current_time);
    begin_month_sec = mktime(&begin_month);

    time_diff = difftime(current_time_sec, begin_month_sec);

    printf("start of the month is %s\n", asctime(&begin_month));
    printf("The current date is %s\n", asctime(current_time));

    printf("The second different between"
            " now and begin of month: %lf\n", time_diff);

    printf("The days between"
            " now and begin of month: %lf\n", time_diff / 60 / 60 / 24);
    return 0;
}