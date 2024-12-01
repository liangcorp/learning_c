#include <stdio.h>

struct month {
    int no_of_dates;
    char name[3];
};

int main()
{
    {
        struct month a_month;

        a_month.no_of_dates = 31;
        a_month.name[0] = 'J';
        a_month.name[1] = 'a';
        a_month.name[2] = 'n';

        printf("%s\n", a_month.name);
    }

    {
        struct month a_month = { 31, { 'J', 'a', 'n' } };
    }

    return 0;
}
