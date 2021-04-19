#include <stdio.h>

int main(void)
{
    int value = 5;
    int i = 1, j, k = 0;

    outer_loop:
        if(i < value)
        {
            j = i;

            inner_loop:
                if (j < value)
                {
                    printf(" ");
                    j++;
                    goto inner_loop;
                }
                else
                {
                    inner_loop2:
                        if (k != ((2 * i)))
                        {
                            if (k == 0 || k == (2 * i) - 3)
                            {
                                printf("*");
                            }
                            printf(" ");
                            k++;
                            goto inner_loop2;
                        }

                        k = 0;
                        printf("\n");
                        i++;
                        goto outer_loop;
                }
        }
        else
        {
            i = 0;
            loop:
                if (i < (2 * value) - 1)
                {
                    printf("*");
                    i++;
                    goto loop;
                }
        }

    return 0;
}