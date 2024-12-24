#include <stdio.h>

void funct1 (int);
void funct2 (int);

typedef void FuncType(int);

int main()
{
    FuncType *func_ptr = NULL;

    func_ptr = funct1;


    (*func_ptr)(100);

    func_ptr = funct2;

    (*func_ptr)(200);

    return 0;
}

void funct1(int i)
{
    printf("funct1 got an argument of %d\n", i);
}

void funct2(int i)
{
    printf("funct2 got an argument of %d\n", i);
}
