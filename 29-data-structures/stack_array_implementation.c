#include <stdio.h>

#define MAXSIZE 5

struct stack {
	int stk[MAXSIZE];
	int top;
};

typedef struct stack STACK;

STACK s;

int push(int num);
int pop(void);
void display(void);

int main()
{
	return 0;
}

int push(int num)
{
	if (s.top == (MAXSIZE - 1)) {
		printf("Stack is full\n");
		return -1;
	} else {
		s.top = s.top + 1;
		s.stk[s.top] = num;
	}
	return 0;
}

int pop()
{
	int num = 0;
	if (s.top == -1) {
		printf("Stack is empty\n");
		return (s.top);
	} else {
		num = s.stk[s.top];
		printf("popped element is = %d\n", s.stk[s.top]);
		s.top = s.top - 1;
	}
	return num;
}

void display()
{
	int i = 0;
	if (s.top == -1) {
		printf("Stack is empty\n");
	} else {
		printf("\nThe status of the stack is:\n");
		for (i = s.top; i >= 0; i--)
			printf("%d\n", s.stk[i]);
	}
	printf("\n");
}
