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

typedef struct node
{
    int value;
    int index;
    struct node *next_node_ptr;
} node_t;

/*
    Memory needs to be allocated in the functions. Pass the address
    of the struct node is pass by copy. Allocating memory for the copy
    doesn't allocate for the original. Therefore, it's important to
    use double pointer.
    For example:

    void foo(char* ptr)
    {

        // Won't work for main because ptr is not the original ptr

        ptr = (char *) malloc(255 * sizeof(char));
        strcpy(ptr, "Hello World");
    }

    int main(void)
    {
        char *ptr = NULL;
        foo(ptr);   // Crashes the program due to memory not allocated
        printf("%s\n", ptr);

        free(ptr);

        return 0;
    }

    "struct node" is "node_t"
    struct node *node_ptr; is the same as
    node_t *node_ptr;
    i.e. node_ptr is pointer to a node.
 */

void insert_at_first(node_t **head, int value);
void insert_at_last(node_t **head, int value);
void insert_at_position(node_t **head, int value, int position);
void delete_first_occurrence(node_t **head, int input_value);
void delete_at_position(node_t **head, int position);
void update_value_at_position(node_t **head, int input_value, int position);
int find_element(node_t *head, int input_value);
void display_list(node_t *head);
void free_memory(node_t *head);
