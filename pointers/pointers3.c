#include <stdio.h>

int main(void)
{
    long num1 = 0L;
    long num2 = 0L;
    long *p_num = NULL;

    p_num = &num1;
    *p_num = 2L;
    ++num2;
    num2 += *p_num;

    p_num = &num2;
    ++*p_num;

    printf("num1 = %ld num2 = %ld *p_num = %ld *p_num + num2 = %ld\n",
                       num1, num2, *p_num, *p_num + num2);

    return 0;
}