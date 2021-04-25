#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item
{
    char *item_name;
    int qty;
    float price;
    float amount;
};

void read_item(struct item *i);
void print_item(struct item *i);

int main(void)
{
    struct item itm;

    struct item *p_item;

    p_item = &itm;
    p_item->item_name = (char *)malloc(30 * sizeof(char));

    if(p_item)
        exit(-1);
    else
    {
        read_item(p_item);
        print_item(p_item);
    }

    free(p_item->item_name);
    return 0;
}

void read_item(struct item *i)
{
    printf("Enter product name: ");
    scanf("s", i->item_name);

    printf("Enter price: ");
    scanf("%f", &i->price);

    printf("Enter quantity: ");
    scanf("%d", &i->qty);

    i->amount = i->price * (float)i->qty;
}

void print_item(struct item *i)
{
    printf("\nName: %s", i->item_name);
    printf("\nPrice: %f", i->price);
    printf("\nQuantity: %d", i->qty);
    printf("\nTotal Amount: %.2f", i->amount);
}
