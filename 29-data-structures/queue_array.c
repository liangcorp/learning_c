#include <stdio.h>

#define MAX 50

int enqueue(int add_item);
int dequeue();
void display();

int queue_array[MAX];
int rear = -1;
int front = -1;

int main()
{
	return 0;
}

int enqueue(int add_item)
{
	if (rear == MAX - 1) {
		printf("Queue Overflow\n");
		return -1;
	} else {
		if (front == -1)
			front = 0;

		rear = rear + 1;
		queue_array[rear] = add_item;
	}
	return 0;
}

int dequeue()
{
	if (front == -1 || front > rear) {
		printf("Queue underflow\n");
		return -1;
	} else {
		printf("Element deleted from queue is: %d\n",
		       queue_array[front]);
		front = front + 1;
	}

	return 0;
}

void display()
{
	int i;
	if (front == -1)
		printf("Queue is empty\n");
	else {
		printf(" Queue is: \n");
		for (i = front; i <= rear; i++)
			printf("%d ", queue_array[i]);
		printf("\n");
	}
}
