#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
};

struct Node *top = NULL;

int push(int data)
{
	struct Node *temp = NULL;

	temp = malloc(sizeof(struct Node));

	if (temp == NULL) {
		fprintf(stderr, "Can not allocation memory\n");
		return -1;
	}

	temp->data = data;
	temp->link = top;
	top = temp;

	return 0;
}

int is_empty()
{
	return top == NULL;
}

int pop()
{
	struct Node *temp;

	if (top != NULL) {
		temp = top;
		top = top->link;
		temp->link = NULL;
		free(temp);
	}

	return 0;
}

void display()
{
	struct Node *temp;

	if (top != NULL) {
		temp = top;
		while (temp != NULL) {
			printf("%d:\n", temp->data);
			temp = temp->link;
		}
	}
}

int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(4);
	push(6);

	display();

	pop();
	pop();

	display();

	return 0;
}
