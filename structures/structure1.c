#include <stdio.h>

struct date
{
    int month;
    int day;
    int year;
};

int main(void)
{
   struct date today = {.month = 12, .day = 10};

   today.day = 30;
   today.year = 2021;

   return 0;
}
