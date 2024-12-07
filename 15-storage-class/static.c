#include <stdio.h>

void fun()
{
    /*
       static variable have a property of perserving
       their value even after they are out of their
       scope
        - static variable preserve the value of their
        last use in their scope
        - no new memory is allocated because they are
        not re-declared
        - their scope is local to the function to
        which they were defined
        - allocated on the heap
        - has default value of 0
        - only initialized once
    */

    /*
       making local variable static allow them to
       maintain their values between function calls
        - does not create and destroy the local variable
        each time it comes into and goes out of scope
    */

    /*
        If you want variable to be global but NOT
        external
    */

    /*
       static variables should not be declared inside a structure
        C compiler requires the entire structure elements to be
        placed together
        - meomry allocation for structure members should be
        contiguous

        All structure members should reside in the same memory
        segment
        - the value for the structure elements is fecthed by counting
        the offset of the element from the beginning address of
        the structure
        - separating out one of the member alone to data segment
        defeats the purpose of a static variable
    */

    static int count = 0;
    int local_var = 0;

    printf("automatic = %d, static = %d\n", local_var, count);

    count++;
    local_val++;
}

int main()
{
    fun();
    fun();

    return 0;
}


