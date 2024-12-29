#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node *next_node;
} node_t;

typedef node_t *list_node_ptr;

void insert(list_node_ptr *head, char value);
void insert_at_end(list_node_ptr *head, char value);
void insert_at_beginning(list_node_ptr *head, char value);
char delete(list_node_ptr *head, char value);
int delete_at_beginning(list_node_ptr *head);
int is_empty(list_node_ptr head);
void print_list(list_node_ptr current_node);

int main(void)
{
	list_node_ptr head = NULL;
	int choice = 0;
	char item = '\0';

	insert(&head, item);

	return 0;
}

void insert_at_beginning(list_node_ptr *head, char val)
{
	list_node_ptr new_node = malloc(sizeof(node_t));
	new_node->data = val;
	new_node->next_node = *head;
	*head = new_node;
}

void insert_at_end(list_node_ptr *head, char val)
{
	list_node_ptr current = *head;

	if (current != NULL) {
		while (current->next_node != NULL)
			current = current->next_node;

		current->next_node = malloc(sizeof(node_t));
		current->next_node->data = val;
		current->next_node->next_node = NULL;
	} else {
		current = malloc(sizeof(node_t));
		current->data = val;
		current->next_node = NULL;
		*head = current;
	}
}

void insert(list_node_ptr *head, char value)
{
	list_node_ptr new_node;
	list_node_ptr previous_node;
	list_node_ptr current_node;

	new_node = malloc(sizeof(node_t));

	if (new_node != NULL) {
		new_node->data = value;
		new_node->next_node = NULL;

		previous_node = NULL;
		current_node = *head;

		while (current_node != NULL && value > current_node->data) {
			previous_node = current_node;
			current_node = current_node->next_node;
		}

		if (previous_node == NULL) {
			new_node->next_node = *head;
			*head = new_node;
		} else {
			previous_node->next_node = new_node;
			new_node->next_node = current_node;
		}
	} else {
		printf("%c not inserted. No memory available.\n", value);
	}
}

int delete_at_beginning(list_node_ptr *head)
{
	list_node_ptr temp_node = NULL;

	if (head == NULL) {
		return -1;
	} else {
		temp_node = *head;
		*head = (*head)->next_node;
		free(temp_node);
	}
	return 0;
}

char delete(list_node_ptr *head, char value)
{
	list_node_ptr previous_node;
	list_node_ptr current_node;
	list_node_ptr temp_node;

	if (value == (*head)->data) {
		temp_node = *head;
		*head = (*head)->next_node;
		free(temp_node);
	} else {
		previous_node = *head;
		current_node = (*head)->next_node;

		while (current_node != NULL && current_node->data != value) {
			previous_node = current_node;
			current_node = current_node->next_node;
		}

		if (current_node != NULL) {
			temp_node = current_node;
			previous_node->next_node = current_node->next_node;
			free(temp_node);
			return value;
		}
	}
	return '\0';
}

void print_list(list_node_ptr current_node)
{
	if (current_node == NULL) {
		printf("List is empty.\n");
	} else {
		printf("The list is:\n");

		while (current_node != NULL) {
			printf("%c --> ", current_node->data);
			current_node = current_node->next_node;
		}
		printf("NULL\n");
	}
}

int is_empty(list_node_ptr head)
{
	return head == NULL;
}
