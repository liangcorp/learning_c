#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler_dividedbyzero(int signum);

int main(void)
{
    int result = 0;
    int v1 = 121;
    int v2 = 0;

    void (*sigHandlerReturn)(int);

    sigHandlerReturn = signal(SIGFPE, handler_dividedbyzero);

    if (sigHandlerReturn == SIG_ERR)
    {
        perror("Signal Error: ");
        return 1;
    }

    result = v1 / v2;

    printf("Result of Divide by zero is %d\n", result);

    return 0;
}

void handler_dividedbyzero(int signum)
{
    if (signum == SIGFPE)
    {
        printf("Received SIGFPE, Divide by Zero Exception\n");
        exit(0);
    }
    else
    {
        printf("Recieved %d Signal\n", signum);
        return ;
    }
}