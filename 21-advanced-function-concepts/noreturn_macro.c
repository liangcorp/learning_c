#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void my_exit(void);

/* calls exit() and doesn't return to its caller. */
void my_exit(void)
{
    printf("Existing...\n");
    exit(0);
}

int main(void)
{
    my_exit();

    return 0;
}
