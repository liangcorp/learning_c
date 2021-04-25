#include <stdio.h>
int main()
{
    enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};

    enum Company xeros = XEROX;
    enum Company google = GOOGLE;
    enum Company ebay = EBAY;

    printf("Xerox: %d\n", xeros);
    printf("Google: %d\n", google);
    printf("Ebay: %d\n", ebay);

    return 0;
}
