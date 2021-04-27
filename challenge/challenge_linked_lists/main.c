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

void clear_screen()
{
    printf("\e[1;1H\e[2J"); //  clear screen
}

void display_choices(void)
{
    printf("\n--------------------------------------------\n");
    printf("\nYou choices:\n"
            "\t1. Insert integer at the beginning\n"
            "\t2. Insert integer at the end\n"
            "\t3. Insert integer at a position\n"
            "\t4. Delect the first matched integer\n"
            "\t5. Delect an integer at an index location\n"
            "\t6. Update an integer at an index location\n"
            "\t7. Find an integer's location\n"
            "\t8. Display the linked list\n"
            "\t9. Exit\n\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Your selection: ");
}

int main(void)
{
    node_t *head = NULL;

    int selection = 0;
    int input_value = 0;
    int input_position = 0;

    while (selection != 9)
    {
        display_choices();
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            printf("Input an integer: ");
            scanf("%d", &input_value);
            insert_at_first(&head, input_value);
            clear_screen();
            break;

        case 2:
            printf("Input an integer: ");
            scanf("%d", &input_value);
            insert_at_last(&head, input_value);
            clear_screen();
            break;

        case 3:
            printf("Input a postion: ");
            scanf("%d", &input_position);
            printf("Input an integer: ");
            scanf("%d", &input_value);
            insert_at_position(&head, input_value, input_position);
            break;

        case 4:
            printf("Input an integer: ");
            scanf("%d", &input_value);
            delete_first_occurrence(&head, input_value);
            break;

        case 5:
            printf("Input an index postion: ");
            scanf("%d", &input_position);
            delete_at_position(&head, input_position);
            break;

        case 6:
            printf("Input an index position: ");
            scanf("%d", &input_position);
            printf("Input an value: ");
            scanf("%d", &input_value);
            update_value_at_position(&head, input_value, input_position);
            break;

        case 7:
            printf("Input an value to find: ");
            scanf("%d", &input_value);
            find_element(head, input_value);
            break;

        case 8:
            clear_screen();
            printf("Display the linked list:\n");
            display_list(head);
            break;

        case 9:
            exit(EXIT_SUCCESS);

        default:
            printf("Invalid input. Try again\n");
            break;
        }
    }

    #ifdef DEBUG
        printf("Insert at first\n");
    #endif

/*     insert_at_first(&head, 2);
    insert_at_first(&head, 3);
    insert_at_first(&head, 4);
    insert_at_first(&head, 5);
    insert_at_first(&head, 6);
    insert_at_last(&head, 10);
    insert_at_last(&head, 9);
    insert_at_last(&head, 8);
    insert_at_position(&head, 100, 3);
    insert_at_position(&head, 100, 8);
    delete_first_occurrence(&head, 11);
    delete_first_occurrence(&head, 6);
    delete_first_occurrence(&head, 5);
    delete_at_position(&head, 11);
    delete_at_position(&head, 2);
    display_list(head);
    update_value_at_position(&head, 2, 111);
    update_value_at_position(&head, 2, 8);
    find_element(head, 2);
    find_element(head, 1000);

    #ifdef DEBUG
        printf("Display list\n");
    #endif


    display_list(head);
 */
    free_memory(head);

    return 0;
}