#include <stdio.h>

int main()
{

    enum Company {
        GOOGLE,
        FACEBOOK,
        XEROX,
        YAHOO,
        EBAY,
        MICROSOFT
    };

    enum Company xerox = XEROX;
    enum Company google = GOOGLE;
    enum Company ebay = EBAY;

    printf("Xerox value is: %d\n", xerox);
    printf("Google value is: %d\n", google);
    printf("Ebay value is: %d\n", ebay);

    return 0;
}
