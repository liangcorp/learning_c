#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct tree_node {
	int data;
	struct tree_node *left_ptr;
	struct tree_node *right_ptr;
};

typedef struct tree_node TreeNode;
typedef TreeNode *TreeNodePtr;

void insert_node(TreeNodePtr *tree_ptr, int value);
void in_order(TreeNodePtr tree_ptr);
void pre_order(TreeNodePtr tree_ptr);
void post_order(TreeNodePtr tree_ptr);

int main()
{
	int i = 0;
	int item = 0;
	TreeNodePtr root_ptr = NULL;

	srand(time(NULL));
	printf("The numbers being placed in the tree are:\n");

	for (i = 1; i <= 10; i++) {
		item = rand() % 15;
		printf("%3d", item);
		insert_node(&root_ptr, item);
	}

	printf("\nThe pre-order traversal is:\n");
	pre_order(root_ptr);

	printf("\nThe in-order traversal is:\n");
	in_order(root_ptr);

	printf("\nThe post-order traversal is:\n");
	post_order(root_ptr);

	return 0;
}

void insert_node(TreeNodePtr *tree_ptr, int value)
{
	if (*tree_ptr == NULL) {
		*tree_ptr = malloc(sizeof(TreeNode));

		if (*tree_ptr != NULL) {
			(*tree_ptr)->data = value;
			(*tree_ptr)->left_ptr = NULL;
			(*tree_ptr)->right_ptr = NULL;
		} else {
			printf("%d not inserted, No memory available.\n",
			       value);
		}
	} else {
		if (value < (*tree_ptr)->data) {
			insert_node(&((*tree_ptr)->left_ptr), value);
		} else if (value > (*tree_ptr)->data) {
			insert_node(&((*tree_ptr)->right_ptr), value);
		} else {
			printf("dup");
		}
	}
}

void in_order(TreeNodePtr tree_ptr)
{
	if (tree_ptr != NULL) {
		in_order(tree_ptr->left_ptr);
		printf("%3d", tree_ptr->data);
		in_order(tree_ptr->right_ptr);
	}
}

void pre_order(TreeNodePtr tree_ptr)
{
	if (tree_ptr != NULL) {
		printf("%3d", tree_ptr->data);
		pre_order(tree_ptr->left_ptr);
		pre_order(tree_ptr->right_ptr);
	}
}

void post_order(TreeNodePtr tree_ptr)
{
	if (tree_ptr != NULL) {
		post_order(tree_ptr->left_ptr);
		post_order(tree_ptr->right_ptr);
		printf("%3d", tree_ptr->data);
	}
}
