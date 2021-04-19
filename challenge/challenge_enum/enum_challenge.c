#include <stdio.h>

int main()
{
	enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO = 10, EBAY, MICROSOFT};

	enum Company xerox = XEROX;
	enum Company google = GOOGLE;
	enum Company ebay = EBAY;

	printf("Company xerox is: %d\n", xerox);
	printf("Company google is: %d\n", google);
	printf("Company ebay is: %d\n", ebay);

	return 0;
}
