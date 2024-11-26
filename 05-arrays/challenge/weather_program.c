#include <stdio.h>

#define YEARS 5
#define MONTHS 12

int main()
{
	double sum = 0.0;
	int i, j;

	int list_of_years[YEARS] = { 2010, 2011, 2012, 2013, 2014 };

    double monthly_average[MONTHS] = { 0.0 };

    float rain_fall[YEARS][MONTHS] = {
        {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0},
        {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0},
        {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0},
        {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0},
        {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0}
    };

    printf("YEAR\tRAINFALL (inches)\n");

    for (i = 0; i < YEARS; i++) {
        sum = 0.0;
        for (j = 0; j < MONTHS; j++) {
            sum += rain_fall[i][j];
        }
        printf("%d\t%.2lf\n", list_of_years[i], sum);
    }

    for (j = 0; j < MONTHS; j++) {
        sum = 0.0;
        for ( i = 0; i < YEARS; i++) {
            sum += rain_fall[i][j];
        }
        monthly_average[j] = sum / MONTHS;
    }

    printf("\nJan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");
    for (i = 0; i < MONTHS; i++)
        printf("%.2lf\t", monthly_average[i]);

    printf("\n");

    return 0;
}
