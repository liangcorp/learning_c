#include <stdio.h>
#include <stdlib.h>

struct Item {
    char *item_name;
    int quantity;
    float price;
    float amount;
};

void read_item(struct Item *item_ptr)
{
    printf("Enter a item name: ");
    scanf("%s", item_ptr->item_name);

    printf("Enter the item price: ");
    scanf("%f", &item_ptr->price);

    printf("Enter the item quantity: ");
    scanf("%d", &item_ptr->quantity);

    item_ptr->amount = item_ptr->price * (float)item_ptr->quantity;
}

void print_item(struct Item *item_ptr)
{
    printf("Name: %s\n", item_ptr->item_name);
    printf("Quantity: %d\n", item_ptr->quantity);
    printf("Price: %.2f\n", item_ptr->price);
    printf("Amount: %.2f\n", item_ptr->amount);
}

int main()
{
    struct Item item1;
    item1.item_name = (char *)malloc(50 * sizeof(char));

    if (item1.item_name == NULL)
        exit(-1);

    read_item(&item1);
    print_item(&item1);

    free(item1.item_name);
    item1.item_name = NULL;

    return 0;
}
