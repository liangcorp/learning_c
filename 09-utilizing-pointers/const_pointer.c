#include <stdio.h>

int main()
{
    int value = 5;

    const int *p_value = &value;

    *p_value = 10;  //  ERROR: Can't change value via dereference pointer
    p_value = NULL; //  Ok
    value = 10;     // Ok

    int *const p2_value = &value;
    *p2_value = 10;     //  Ok
    p2_value = NULL;    //  ERROR: Can't change pointer value
    value = 10;         //  Ok

    const int *const p3_value = &value;
    *p3_value = 10;     //  ERROR: Can't change value via deference pointer
    p3_value = NULL;    //  ERROR: Can't change pointer value
    value = 10;         //  Ok

    return 0;
}
