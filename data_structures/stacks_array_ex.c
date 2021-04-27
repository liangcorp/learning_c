#include <stdio.h>

#define MAXSIZE 5

struct stack
{
    int stk[MAXSIZE];
    int top;
};

typedef struct stack STACK;

STACK s;

void push(void);
int pop(void);
void display(void);

void main(void)
{
    int choice;
    int option = 1;
    s.top = -1;

    while (option)
    {
        printf("---------------------------------------------\n");
        printf("\t1\t-->\tPUSH\n");
        printf("\t2\t-->\tPOP\n");
        printf("\t3\t-->\tDISPLAY\n");
        printf("\t4\t-->\tEXIT\t");
        printf("---------------------------------------------\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
        }

        fflush (stdin);
        printf("Do you want to continue (Type 0 or 1)?\n");
        scanf("%d", &option);
    }
}

void push(void)
{
    int num = 0;
    if (s.top == (MAXSIZE - 1))
    {
        printf("Stack is Full\n");
        return;
    }
    else
    {
        printf("Enter the element to be pushed\n");
        scanf("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}

int pop()
{
    int num = 0;
    if (s.top == -1)
    {
        printf("Stack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.stk[s.top];
        printf("popped element is =%d\n",s.stk[s.top]);
        s.top = s.top - 1;
    }
    return(num);
}

void display(void)
{
    int i = 0;
    if (s.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("\nThe status of the stack is\n");
        for (i = s.top; i >= 0; i--)
        {
            printf("%d\n", s.stk[i]);
        }
    }
    printf("\n");
}