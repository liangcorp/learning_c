#include <stdio.h>

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

int main()
{
	int hours = 0;
	int overtime_hours = 0;
	float overtime_rate = PAYRATE * 1.5F;

	float gross_pay = 0.0F;
	float taxes = 0.0F;
	float net_pay = 0.0F;

	printf("Enter the number of hours worked in a week: ");
	scanf("%d", &hours);

	if ((overtime_hours = hours - OVERTIME) > 0)
		gross_pay = PAYRATE * OVERTIME + overtime_rate * overtime_hours;
	else
		gross_pay = hours * PAYRATE;

	if (gross_pay > 450)
		taxes = 300 * TAXRATE_300 + 150 * TAXRATE_150 +
			(gross_pay - 450) * TAXRATE_REST;
	else if (gross_pay <= 450 && gross_pay > 300)
		taxes = 300 * TAXRATE_300 + (gross_pay - 300) * TAXRATE_150;
	else
		taxes = gross_pay * TAXRATE_300;

	net_pay = gross_pay - taxes;

	printf("Gross pay: %.2f\n", gross_pay);
	printf("Taxes: %.2f\n", taxes);
	printf("Net pay: %.2f\n", net_pay);

	return 0;
}
