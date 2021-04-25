#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LENGTH 20

struct item
{
    char *item_name;
    int quantity;
    float price;
    float amount;
};

void read_item(struct item *p_item)
{
    printf("Input a fruit name: ");
    scanf("%s", p_item->item_name);
    printf("Input quantity: ");
    scanf("%d", &(p_item->quantity));
    printf("Input price: ");
    scanf("%f", &(p_item->price));

    p_item->amount = p_item->quantity * p_item->price;
}

void print_item(struct item *p_item)
{
    printf("Item information:\n");
    printf("Name: %s\n", p_item->item_name);
    printf("Quantity: %d\n", p_item->quantity);
    printf("Price: %.2f\n", p_item->price);
    printf("Amount: %.2f\n", p_item->amount);
}

int main(void)
{
    struct item fruit;

    fruit.item_name = (char *)malloc(NAME_LENGTH);

    read_item(&fruit);
    print_item(&fruit);

    return 0;
}
