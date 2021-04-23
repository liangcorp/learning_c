#include <stdio.h>
#include <stdlib.h>

/*
    gcc -D DEBON debug2_macro_level.c -o debug2_macro_level
    $ ./debug2_macro_level 1 5 10
    $ ./debug2_macro_level 2 5 10   
    $ ./debug2_macro_level 3 5 10
 */

int Debug = 0; 

#ifdef DEBON
    #define DEBUG(level, fmt, ...) \
        if (Debug >= level) \
            fprintf(stderr, fmt, __VA_ARGS__)
#else
    #define DEBUG(level, fmt, ...)
#endif

int process (int i, int j)
{
    int val = 0;

    DEBUG(1, "process (%d, %d)\n", i, j);

    val = i * j;

    DEBUG(2, "return %d\n", val);

    return val;
}

int main(int argc, char * argv[])
{
    int arg1 = 0;
    int arg2 = 0;

    if (argc > 2)
    {
        Debug = atoi(argv[1]);
        arg1 = atoi(argv[2]);
    }
    if (argc == 4)
        arg2 = atoi(argv[3]);

    DEBUG(2, "processed %d arguments\n", argc - 1);
    DEBUG(3, "arg1 = %d, arg2 = %d\n", arg1, arg2);
    
    printf("%i\n", process(arg1, arg2));

    return 0; 
}