/*
    Author: Chen Liang
    Description: Implement a linked list data structure include the
                 following functions:
                 - insert_at_begining
                 - insert_at_end
                 - insert
                 - delete
                 - delete_at_begining
                 - is_empty
                 - print_list
    Date: 26th Apr 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/* Self-referential structure */
typedef struct node
{
    char data;
    struct node *next_ptr;
} node_t;

typedef node_t *list_node_ptr;

/* prototypes */
void insert(struct node **head, char value);
void insert_at_end(list_node_ptr *head, char value);
void insert_at_begining(list_node_ptr *head, char value);
char delete(list_node_ptr *head, char value);
void delete_at_beginning(list_node_ptr *head);
int is_empty(list_node_ptr head);
void print_list(list_node_ptr current_ptr);


int main(void)
{
    list_node_ptr head = NULL;  /* initially there are no nodes */
    int choice = 0;             /* user's choice */
    char item = '\0';           /* char entered by user */

    /* display the menu */
    printf("Enter your choice:\n"
        "\t1. Insert an element into the list in alphabetical order.\n"
        "\t2. Insert an element at the end of the list.\n"
        "\t3. Insert an element at the beginning of the list.\n"
        "\t4. Delete an element from the list.\n"
        "\t5. Delete an element from the beginning of the list.\n"
        "\t6. to end.\n");

    printf(":: ");
    scanf("%d", &choice);

    /* loop while user does not choose 3 */
    while (choice != 6)
    {
        switch (choice)
        {
            case 1:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert(&head, item);    /* insert item in list */
                print_list(head);
                break;

            case 2:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                insert_at_end(&head, item); /* insert item in list */
                print_list(head);
                break;

            case 3:
                printf("Enter a character: ");
                scanf("\n%c", &item);
                /* Insert item in list at the beginning */
                insert_at_begining(&head, item);
                print_list(head);
                break;

            case 4: /* delete an element */
                /* if list is not empty */
                if (!is_empty(head))
                {
                    printf("Enter character to be deleted: ");
                    scanf("\n%c", &item);

                    /* if character is found, remove it */
                    if (delete(&head, item))
                    {
                        /* remove item */
                        printf("%c deleted.\n", item);
                        print_list(head);
                    }
                    else
                    {
                        printf("%c not found.\n\n", item);
                    }
                }
                break;

            case 5: /* delete an element at beginning */
                /* if list is not empty */
                if ( !is_empty(head))
                {
                    /* if character is found, remove it */
                    delete_at_beginning(&head);
                    printf("%c deleted.\n", item);
                    print_list(head);
                }
                else
                {
                    printf("List is empty.\n\n");
                }
                break;

            default:
                printf("Invalid choice.\n\n");
                /* display the menu */
                printf("Enter your choice:\n"
                        "\t1. Insert an element into the list.\n"
                        "\t2. Delete an element from the list.\n"
                        "\t3. to end.\n");
                break;
        }   /* end switch */

        printf("? ");
        scanf("%d", &choice);
    }   /* end while */

    printf("End of run.\n");

    return 0;
}

void insert_at_beginning(list_node_ptr *head, char val)
{
    list_node_ptr new_node = malloc(sizeof(struct node));

    new_node->data = val;
    new_node->next_ptr = *head;

    *head = new_node;
}

void insert_at_end(list_node_ptr *head, char val)
{
    list_node_ptr current = *head;

    if (current != NULL)
    {
        while (current->next_ptr != NULL)
        {
            current = current->next_ptr;
        }
        /* now we can add a new variable */
        current->next_ptr = malloc(sizeof(node_t));
        current->next_ptr->data = val;
        current->next_ptr->next_ptr = NULL;
    }
    else
    {
        current = malloc(sizeof(node_t));
        current->data = val;
        current->next_ptr = NULL;
        *head = current;
    }
}

/* Insert a new value into the list in sorted order */
void insert(list_node_ptr *head, char value)
{
    list_node_ptr new_ptr;      /* ptr to new node */
    list_node_ptr previous_ptr; /* ptr to the previous node in list */
    list_node_ptr current_ptr;  /* ptr to the current node in list */

    new_ptr = malloc(sizeof(node_t));   /* create node */

    if (new_ptr != NULL)    /* is space available */
    {
        new_ptr->data = value;      /* place value in node */
        /* node does not link to another node */
        new_ptr->next_ptr = NULL;

        previous_ptr = NULL;
        current_ptr = *head;

        /* loop to find the correct location in the list */
        while (current_ptr != NULL && value > current_ptr->data)
        {
            previous_ptr = current_ptr;             /* walk to ... */
            current_ptr = current_ptr->next_ptr;    /* ... next node */
        }

        /* insert new node at beginning of list */
        if (previous_ptr == NULL)
        {
            new_ptr->next_ptr = *head;
            *head = new_ptr;
        }
        else
        {
            /* insert new node between previous_ptr and current_ptr */
            previous_ptr->next_ptr = new_ptr;
            new_ptr->next_ptr = current_ptr;
        }
    }
    else
    {
        printf("%c not inserted. No memory available.\n", value);
    }
}


void delete_at_beginning(list_node_ptr *head)
{
    list_node_ptr temp_ptr = NULL;  /* temporary node pointer */

    if (head == NULL)
    {
        return;
    }
    else
    {
        temp_ptr = *head;   /* hold onto node being removed */
        *head = (*head)->next_ptr;  /* de-thread the node */
        free(temp_ptr);
    }
}

char delete(list_node_ptr *head, char value)
{
    list_node_ptr previous_ptr; /* ptr to previous node in list */
    list_node_ptr current_ptr;  /* ptr to current node in list */
    list_node_ptr temp_ptr;     /* temporary node pointer */

    /* delete first node */
    if (value == (*head)->data)
    {
        temp_ptr = *head;   /* hold onto node being removed */
        *head = (*head)->next_ptr;  /* de-thread the node */
        free(temp_ptr); /* free the de-threaded node */
        return value;
    }
    else
    {
        previous_ptr = *head;
        current_ptr = (*head)->next_ptr;

        /* loop to find the correct location in the list */
        while (current_ptr != NULL && current_ptr->data != value)
        {
            previous_ptr = current_ptr;     /* walk to ... */
            current_ptr = current_ptr->next_ptr;    /* .. next node */
        }

        /* delete node at current_ptr */
        if (current_ptr != NULL)
        {
            temp_ptr = current_ptr;
            previous_ptr->next_ptr = current_ptr->next_ptr;
            free(temp_ptr);
            return value;
        }
    }

    return '\0';
}

/* print the list */
void print_list(list_node_ptr current_ptr)
{
    /* if list is empty */
    if (current_ptr == NULL)
    {
        printf("List is empty.\n\n");
    }
    else
    {
        printf("The list is:\n");

        /* while not the end of the list */
        while (current_ptr != NULL)
        {
            printf("%c --> ", current_ptr->data);
            current_ptr = current_ptr->next_ptr;
        }
        printf("NULL\n\n");
    }
}

/* Return 1 if the list is emtpy, 0 otherwise */
int is_empty(list_node_ptr head)
{
    return head = NULL;
}