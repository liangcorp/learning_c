#include <stdio.h>

int main()
{
	int minutes = 0;

    double minutes_in_year = (60 * 24) * 265;

	printf("Enter minutes: ");
	scanf("%d", &minutes);

    double year = minutes / minutes_in_year;
    double day = (minutes / 60) / 24;

    printf("%d minutes is approximately %.2lf years and  %.2lf days\n", minutes, year, day);

	return 0;
}
