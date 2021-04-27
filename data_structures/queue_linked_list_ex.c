#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct q_node
{
    int key;
    struct q_node *next;
};

struct queue
{
    struct q_node *front;
    struct q_node *rear;
};

struct q_node *new_node(int k)
{
    struct q_node *temp = (struct q_node*)malloc(sizeof(struct q_node));

    temp->key = k;
    temp->next = NULL;

    return temp;
}

struct queue *create_queue()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));

    q->front = q->rear = NULL;

    return q;
};

void en_queue(struct queue* q, int k)
{
    struct q_node *temp = new_node(k);

    /* If queue is empty, then new node is front and rear both */
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    /* Add the new node at the end of queue and change rear */
    q->rear->next = temp;
    q->rear = temp;
}

struct q_node *de_queue(struct queue *q)
{
    /* If queue is empty, return NULL. */
    if (q->front == NULL)
        return NULL;

    /* Store previous front and move front one node ahead */
    struct q_node *temp = q->front;
    q->front = q->front->next;

    /* If front becomes NULL, then change rear also as NULL */
    if (q->front == NULL)
        q->rear = NULL;

    return temp;
}

int main(void)
{
    struct queue *q = create_queue();

    en_queue(q, 1);
    en_queue(q, 2);

    de_queue(q);
    de_queue(q);

    en_queue(q, 3);
    en_queue(q, 4);
    en_queue(q, 5);

    struct q_node *n = de_queue(q);

    if (n != NULL)
        printf("Dequeued item is %d", n->key);

    return 0;
}