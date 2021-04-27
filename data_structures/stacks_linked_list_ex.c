#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

/* Need to fix this to use local variable */
struct node *top = NULL;

void push(int data)
{
    struct node *temp = malloc(sizeof(struct node));

    if (temp != NULL)
    {
        temp->data = data;
        temp->link = top;
        top = temp;
    }
}

void pop()
{
    struct node *temp;

    if (top != NULL)
    {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

int is_empty(void)
{
    return top == NULL;
}

void display(void)
{
    struct node *temp;
    if (top != NULL)
    {
        temp = top;
        while (temp != NULL)
        {
            printf("%d:\n", temp->data);
            temp = temp->link;
        }
    }
}

int main(void)
{
    push(1);
    push(2);
    push(3);
    push(4);

    display();

    pop();
    pop();

    display();

    return 0;
}