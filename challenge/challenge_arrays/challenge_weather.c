#include <stdio.h>

#define NO_OF_YEARS 5
#define NO_OF_MONTHS 12

int main(void)
{
    float rain_fall[NO_OF_YEARS][NO_OF_MONTHS] = {
                    {2.3, 4.5, 4.3, 7.8, 0.3, 0, 1.3, 2.3, 8.3, 2.6, 2.7, 1.2},
                    {3.2, 4.3, 2.5, 6.5, 4.2, 2, 7.6, 2.2, 1.6, 4, 7.1, 0.9},
                    {0, 0, 0, 3.2, 1.2, 1.5, 1.6, 2.5, 4.6, 6.3, 9.0, 0.9},
                    {8.5, 3, 4, 5.3, 4.5, 2.3, 1.2, 3.1, 5.7, 0.8, 3.3, 2},
                    {9, 7.6, 1.7, 2.7, 4.5, 3.4, 5, 3, 7, 8.9, 3.4, 2.5}
                };

    int years[NO_OF_YEARS] = {2010, 2011, 2012, 2013, 2014};
    int year, month;
    float total = 0.0;
    float each_month_total[NO_OF_MONTHS] = {0.0};
    float monthly_average[NO_OF_MONTHS] = {0.0};
    float yearly_total = 0.0;
    float yearly_average = 0.0;


    printf("YEAR\tRAINFALL (inches)\n");

    for (year=0; year<NO_OF_YEARS; year++)
    {
        for(month=0; month<NO_OF_MONTHS; month++)
        {
            yearly_total += rain_fall[year][month];
        }
        
        total += yearly_total;

        printf("%d\t%.2f\n", years[year], yearly_total);
    }
    
    yearly_average = total / sizeof(years);

    printf("\nThe yearly average is %.2f inches\n\n", yearly_average);

    printf("Jan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");
    for(month=0; month<NO_OF_MONTHS; month++)
    {
        for(year=0; year<NO_OF_YEARS; year++)
        {
            each_month_total[month] += rain_fall[year][month];
        }
        monthly_average[month] = each_month_total[month] / NO_OF_YEARS;
        printf("%.2f\t", monthly_average[month]);
    }
    printf("\n");

    return 0;
}