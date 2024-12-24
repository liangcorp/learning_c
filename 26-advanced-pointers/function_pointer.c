#include <stdio.h>

int some_display();

int main()
{
    int (*func_ptr)();

    func_ptr = some_display;

    printf("Address of function some_display is %p\n", func_ptr);

    (*func_ptr)();

    return 0;
}

int some_display()
{
    printf("Hello world\n");

    return 0;
}
