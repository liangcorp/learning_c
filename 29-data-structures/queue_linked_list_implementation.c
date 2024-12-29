#include <stdio.h>
#include <malloc.h>

struct QNode {
	int key;
	struct QNode *next;
};

struct Queue {
	struct QNode *front;
	struct QNode *rear;
};

struct QNode *new_node(int k)
{
	struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

struct Queue *create_queue()
{
	struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

void en_queue(struct Queue *q, int k)
{
	struct QNode *temp = new_node(k);

	if (q->rear == NULL)
		q->front = q->rear = temp;

	q->rear->next = temp;
	q->rear = temp;
}

struct QNode *de_queue(struct Queue *q)
{
	if (q->front == NULL)
		return NULL;

	struct QNode *temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;

	return temp;
}

int main()
{
	struct Queue *q = create_queue();
	en_queue(q, 1);
	en_queue(q, 2);

	de_queue(q);
	de_queue(q);

	en_queue(q, 3);
	en_queue(q, 4);
	en_queue(q, 5);

	struct QNode *n = de_queue(q);

	if (n != NULL)
		printf("Dequeue item is %d", n->key);

	return 0;
}
