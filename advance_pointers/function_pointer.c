#include <stdio.h>

int some_display ();

int main(void)
{
    int (*func_ptr)();

    func_ptr = some_display;

    printf("\nAddress of function some_display is %p\n", func_ptr);

    (*func_ptr)();

    return 0;
}

int some_display()
{
    printf("\n--Displaying some text--\n");

    return 0;
}