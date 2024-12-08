#include <stdio.h>

typedef int Counter;
typedef int* i_ptr; //  More flexible than #define
                    //  Handled by compiler

#define Counter int // has same effect but just subtitution
                    //  Handled by pre-processor

#define int_pointer int *

int_pointer chalk, cheese;  //  same as int *chalk, cheese;
                            //  cheese is int NOT int*

typedef char * char_ptr;
char_ptr Bently, Rolls_Royce;   //  Both as char*

int main()
{
    Counter i = 0;
    i_ptr p = &i;

    i_ptr my_array[10]; //  same as int *my_array[10]

    return *p;
}
