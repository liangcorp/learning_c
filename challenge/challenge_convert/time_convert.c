#include <stdio.h>
int main()
{
    double minutes;
    double years;
    double days;

    printf("Enter minutes here: ");
    scanf("%lf", &minutes);

    days = minutes / 60 / 24;
    years = days / 365;

    printf("Days: %lf\n", days);
    printf("Years: %lf\n", years);
}
