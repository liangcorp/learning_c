/*
 *  Author: Chen Liang
 *  Description: Write a program that performs operations on a linked
 *                list. The linked list stores integers and uses
 *                pointers.
 *              The program should perform the following operations:
 *              - Insert node at first
 *              - Insert node at last
 *              - Insert node at position
 *              - Delete node from any position
 *              - Update node value
 *              - Search Element in the linked list
 *              - Display list
 *              - Exit
 *  Date 26th April 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linked_list.h"

void insert_at_first(node_t **head, int value)
{
    node_t *new_node = NULL;
    node_t *current_node = NULL;
    int i = 1;

    if ((*head) == NULL)
    {
        #ifdef DEBUG
            printf("Insert into empty linked list\n");
            printf("Allocating memory\n");
        #endif
        (*head) = calloc(1, sizeof(node_t));
        (*head)->index = i;
        (*head)->value = value;
        (*head)->next_node_ptr = NULL;
    }
    else
    {
        #ifdef DEBUG
            printf("Insert into start of linked list\n");
            printf("Allocating memory\n");
        #endif

        new_node = calloc(1, sizeof(node_t));
        new_node->index = i;
        new_node->value = value;
        new_node->next_node_ptr = *head;
        *head = new_node;


        current_node = *head;

        while(current_node != NULL)
        {
            current_node->index = i;
            current_node = current_node->next_node_ptr;
            i++;
        }

        free(current_node);
    }
}

void insert_at_last(node_t **head, int value)
{
    node_t *new_node = NULL;
    node_t *current_node = NULL;
    int i = 1;

    if ((*head) == NULL)   /* If first node is empty */
    {
        #ifdef DEBUG
            printf("Insert into empty linked list\n");
            printf("Allocating memory\n");
        #endif
        (*head) = calloc(1, sizeof(node_t));
        (*head)->index = i;
        (*head)->value = value;
        (*head)->next_node_ptr = NULL;
    }
    else
    {
        current_node = *head;   /* Current node is the first node */

        while(current_node->next_node_ptr != NULL)
        {
            current_node = current_node->next_node_ptr;
            i++;
        }

        #ifdef DEBUG
            printf("Insert at the end of linked list\n");
            printf("Allocating memory\n");
        #endif

        new_node = calloc(1, sizeof(node_t));
        new_node->index = ++i;
        new_node->value = value;
        new_node->next_node_ptr = NULL;


        #ifdef DEBUG
            printf("Appending the last node\n");
        #endif

        current_node->next_node_ptr = new_node;
    }
}

void insert_at_position(node_t **head, int value, int position)
{
    node_t *new_node = NULL;
    node_t *current_node = NULL;
    node_t *previous_node = NULL;
    node_t *next_node = NULL;

    int i = 1;

    current_node = *head;   /* Current node is the first node */

    if (*head == NULL && position == 1)
    {
        #ifdef DEBUG
            printf("Insert into empty linked list\n");
            printf("Allocating memory\n");
        #endif
        (*head) = calloc(1, sizeof(node_t));
        (*head)->index = position;
        (*head)->value = value;
        (*head)->next_node_ptr = NULL;
    }

    else if (*head != NULL && position == 1)
    {
        new_node = calloc(1, sizeof(node_t));
        new_node->index = position;
        new_node->value = value;
        new_node->next_node_ptr = *head;
        *head = new_node;
    }
    else
    {
        while (current_node != NULL)
        {
            current_node = current_node->next_node_ptr;
            i++;
        }

        /* if the input position is too large */
        if (position > i)
        {
            printf("Position too large\n");
        }
        else
        {
            i = 1;
            current_node = *head;   /* Reset to the first node */

            while(current_node->index != (position - 1))
            {
                current_node = current_node->next_node_ptr;
                i++;
            }

            next_node = current_node->next_node_ptr;

            #ifdef DEBUG
                printf("Allocating memory\n");
            #endif

            new_node = calloc(1, sizeof(node_t));
            new_node->index = position;
            new_node->value = value;
            new_node->next_node_ptr = next_node;

            #ifdef DEBUG
                printf("Insert position %d linked list\n", position);
            #endif

            current_node->next_node_ptr = new_node;
        }
    }

    if (new_node != NULL)
    {
        /* Reset the index */
        current_node = new_node;
        while (current_node != NULL)
        {
            current_node->index = position;
            current_node = current_node->next_node_ptr;
            position++;
        }
    }
}

void delete_first_occurrence(node_t **head, int input_value)
{
    #ifdef DEBUG
            printf("Delete %d\n", input_value);
    #endif

    node_t *current_node = NULL;
    node_t *previous_node = NULL;

    int position = 1;

    if (*head == NULL)
    {
        printf("The list is emtpy\n");
    }
    else
    {
        current_node = *head;
        // previous_node = *head;

        #ifdef DEBUG
            printf("Find the element...\n");
        #endif

        while (current_node != NULL)
        {
            if (current_node->value != input_value)
            {
                previous_node = current_node;
                current_node = current_node->next_node_ptr;
            }
            else
            {
                break;
            }
        }

        if (current_node == NULL)
        {
            printf("Input value doesn't exist\n");
        }
        else if(current_node->index == 1)
        {
            (*head) = current_node->next_node_ptr;

            previous_node = *head;
            position = 1;

            while (previous_node != NULL)
            {
                previous_node->index = position;
                previous_node = previous_node->next_node_ptr;
                position++;
            }

            free(current_node);
        }
        else
        {
            previous_node->next_node_ptr = current_node->next_node_ptr;
            position = previous_node->index;

            while (previous_node != NULL)
            {
                previous_node->index = position;
                previous_node = previous_node->next_node_ptr;
                position++;
            }

            free(current_node);
        }
    }
}

void delete_at_position(node_t **head, int position)
{
    node_t *previous_node = NULL;
    node_t *current_node = NULL;
    _Bool found_position = 0;
    int index = 0;

    current_node = *head;

    if (*head == NULL)
    {
        printf("The list is emtpy\n");
    }
    else if (position == 1)
    {
        while (current_node != NULL)
        {
            current_node->index = index;
            current_node = current_node->next_node_ptr;
            index++;
        }
        (*head) = (*head)->next_node_ptr;
    }
    else
    {
        current_node = *head;

        while (current_node != NULL)
        {
            if (current_node->index == position)
            {
                found_position = 1;
                break;
            }
            else
            {
                previous_node = current_node;
                current_node = current_node->next_node_ptr;
                found_position = 0;
            }
        }

        if (found_position == 1)
        {
            previous_node->next_node_ptr = current_node->next_node_ptr;

            position--;

            while (previous_node != NULL)
            {
                previous_node->index = position;
                previous_node = previous_node->next_node_ptr;
                position++;
            }
        }
        else
        {
            printf("Position doesn't exist\n");
        }

        free(current_node);
    }
}

void update_value_at_position(node_t **head, int input_value, int position)
{
    node_t *current_node = NULL;
    _Bool found_position = 0;

    if (*head == NULL)
    {
        printf("The list is emtpy\n");
    }
    else
    {
        current_node = *head;

        while (current_node != NULL)
        {
            if (current_node->index == position)
            {
                found_position = 1;
                break;
            }
            else
            {
                current_node = current_node->next_node_ptr;
                found_position = 0;
            }
        }

        if (found_position == 1)
        {
            current_node->value = input_value;
        }
        else
        {
            printf("Position doesn't exist\n");
        }
    }

}

int find_element(node_t *head, int input_value)
{
    node_t *current_node = NULL;

    _Bool found_value = 0;

    int position = 1;

    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        current_node = head;

        while (current_node != NULL)
        {
            if (current_node->value == input_value)
            {
                found_value = 1;
                break;
            }
            else
            {
                current_node = current_node->next_node_ptr;
                found_value = 0;
            }
            position++;
        }
    }

    if (found_value == 1)
    {
        printf("Found value at %d\n", position);
        return position;
    }
    else
    {
        printf("Value not found\n");
        return -1;
    }
}

void display_list(node_t *head)
{
    node_t *current_node = NULL;

    if (head == NULL)
    {
        printf("The list is emtpy\n");
    }
    else
    {
        current_node = head;

        printf("Printing the linked list:\n");
        printf("Index\t-->\tValue\n");
        while (current_node != NULL)
        {
            printf("%d\t-->\t%d\n", current_node->index,
                                    current_node->value);
            current_node = current_node->next_node_ptr;
        }
        free(current_node);
    }
}

void free_memory(node_t *head)
{
    node_t *current_node = NULL;
    node_t *free_node = NULL;

    if (head == NULL)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        current_node = head;

        #ifdef DEBUG
            printf("Free memory\n");
        #endif

        while (current_node != NULL)
        {
            free_node = current_node;
            current_node = current_node->next_node_ptr;
            free(free_node);
        }
    }
}