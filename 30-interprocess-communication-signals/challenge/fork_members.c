#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t n1 = fork();
    pid_t n2 = fork();

    if (n1 > 0 && n2 > 0) {
        printf("parent\n");
        printf("%d %d\n", n1, n2);
        printf("    my id is %d\n", getpid());
        printf("    my parentid is %d\n", getppid());
    } else if (n1 == 0 && n2 > 0) {
        printf("\nFirst child\n");
        printf("%d %d\n", n1, n2);
        printf("    my id is %d\n", getpid());
        printf("    my parentid is %d\n", getppid());
    } else if (n1 > 0 && n2 == 0) {
        printf("\nSecond child\n");
        printf("%d %d\n", n1, n2);
        printf("    my id is %d\n", getpid());
        printf("    my parentid is %d\n", getppid());
    } else {
        printf("\nThird child\n");
        printf("%d %d", n1, n2);
        printf("    my id is %d\n", getpid());
        printf("    my parentid is %d\n", getppid());
    }

    return 0;
}

