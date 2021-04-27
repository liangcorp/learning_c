#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* self-referential structure */
struct tree_node
{
    int data;   /* node value */
    struct tree_node *left_ptr;     /* pointer to left subtree */
    struct tree_node *right_ptr;    /* pointer to right subtree */
};

typedef struct tree_node TreeNode;
typedef TreeNode *TreeNodePtr;

/* prototypes */
void insert_node(TreeNodePtr *tree_ptr, int value);
void in_order(TreeNodePtr tree_ptr);
void pre_order(TreeNodePtr tree_ptr);
void post_order(TreeNodePtr tree_ptr);

int main(void)
{
    int i = 0;  /* counter to loop from 1 - 10 */
    int item = 0;   /* variable to hold random values */
    TreeNodePtr root_ptr = NULL;    /* tree initial empty */

    srand(time(NULL));
    printf("The numbers being placed in the tree are: \n");

    /* insert random values between 0 and 14 in the tree */
    for (i = 1; i <= 10; i++)
    {
        item = rand() % 15;
        printf("%3d", item);
        insert_node(&root_ptr, item);
    }

    /* traverse the tree preorder */
    printf("\n\nThe preorder traversal is:\n");
    pre_order(root_ptr);

    /* traverse the tree inorder */
    printf("\n\nThe inorder traversal is:\n");
    in_order(root_ptr);

    /* traverse the tree postorder */
    printf("\n\nThe postorder traversal is:\n");
    post_order(root_ptr);

    return 0;
}

void insert_node(TreeNodePtr *tree_ptr, int value)
{
    if (*tree_ptr == NULL)
    {
        *tree_ptr = malloc(sizeof(TreeNode));

        /* if memory was allocated then assign data */
        if (*tree_ptr != NULL)
        {
            (*tree_ptr)->data = value;
            (*tree_ptr)->left_ptr = NULL;
            (*tree_ptr)->right_ptr = NULL;
        }
        else
        {
            printf("%d not inserted. No memory available.\n", value);
        }
    }
    else    /* tree is not empty */
    {
        /* data to insert is less than data in current node */
        if (value < (*tree_ptr)->data)
        {
            insert_node(&((*tree_ptr)->left_ptr), value);
        }
        /* data to insert is greater than data in current node */
        else if (value > (*tree_ptr)->data)
        {
            insert_node(&((*tree_ptr)->right_ptr), value);
        }
        /* duplicated data value ignored */
        else
        {
            printf("dup\n");
        }
    }
}

void in_order(TreeNodePtr tree_ptr)
{
    if (tree_ptr!= NULL)
    {
        in_order(tree_ptr->left_ptr);
        printf("%3d", tree_ptr->data);
        in_order(tree_ptr->right_ptr);
    }
}

void pre_order(TreeNodePtr tree_ptr)
{
    if (tree_ptr != NULL)
    {
        printf("%3d", tree_ptr->data);
        pre_order(tree_ptr->left_ptr);
        pre_order(tree_ptr->right_ptr);
    }
}

void post_order(TreeNodePtr tree_ptr)
{
    if (tree_ptr != NULL)
    {
        post_order(tree_ptr->left_ptr);
        post_order(tree_ptr->right_ptr);
        printf("%3d", tree_ptr->data);
    }
}