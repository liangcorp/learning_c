#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void en_queue();
void de_queue();
void display();

int queue_array[MAX];
int rear = -1;
int front = -1;

int main(void)
{
    int choice;

    while (1)
    {
        printf("1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            en_queue();
            break;

        case 2:
            de_queue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    }
    return 0;
}

void en_queue()
{
    int add_item = 0;

    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        printf("Insert the element in queue: ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

void de_queue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is: %d\n",
                                            queue_array[front]);
        front = front + 1;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d", queue_array[i]);
        }
        printf("\n");
    }
}