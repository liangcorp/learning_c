#include <stdio.h>

static double this_file_only;
float a_global_var;

static void file_only_func(void)
{
    printf("printf something\n");
}

int main(void)
{
    int auto_var;

    static float permanent_local_var;

    register int register_var;

    return 0;
}