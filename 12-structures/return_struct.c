#include <stdio.h>

#define FUNDLEN 100

struct Funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(struct Funds moolah)
{
    return (moolah.bankfund + moolah.savefund);
}

int main(void)
{
    struct Funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Saving and Load",
        8543.94
    };

    printf("Stan has a total of $%.2f.\n: ", sum(stan));

    return 0;
}
