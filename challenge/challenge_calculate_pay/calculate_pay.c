#include <stdio.h>

#define BASIC_PAY 12.00             //  $12.00 per hour
#define OVERTIME_PAY 18.00          //  $18.00 per hour

#define TAX_RATE_300 0.15           // 15% of the first $300
#define TAX_RATE_NEXT_150 0.20      // 20% of the next $150
#define TAX_RATE_REST 0.25          // 25% of the rest

#define NORMAL_WORK_HOUR_WEEK 40    // 40 hour work week

int main()
{
    int no_of_work_hour = 0;
    int excess_work_hour = 0;

    float gross_pay = 0.0;
    float taxes = 0.0;
    float net_pay = 0.0;

    printf("Number of hours worked in this week: ");
    scanf("%d", &no_of_work_hour);

    if (no_of_work_hour >= NORMAL_WORK_HOUR_WEEK)
    {
        excess_work_hour = no_of_work_hour - NORMAL_WORK_HOUR_WEEK;

        gross_pay = BASIC_PAY * NORMAL_WORK_HOUR_WEEK + OVERTIME_PAY * excess_work_hour;
    }
    else
    {
        gross_pay = BASIC_PAY * no_of_work_hour;
    }

    printf("Gross pay: %.2f\n", gross_pay);

    if (gross_pay <= 300)
    {
        taxes = gross_pay * TAX_RATE_300;
    }
    else if (gross_pay > 300 && gross_pay <= 450)
    {
        taxes = (gross_pay - 300) * TAX_RATE_NEXT_150 + 300 * TAX_RATE_300;
    }
    else
    {
        taxes = (gross_pay - 450) * TAX_RATE_REST + 150 * TAX_RATE_NEXT_150 + 300 * TAX_RATE_300;
    }

    printf("Taxes: %.2f\n", taxes);

    net_pay = gross_pay - taxes;

    printf("Net pay: %0.2f\n", net_pay);

    return 0;
}
