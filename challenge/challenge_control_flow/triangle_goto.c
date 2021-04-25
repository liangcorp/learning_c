/* 
    Description: use goto to print the following

            *
           * *
          *   *
         *     *
        *********
*/
#include <stdio.h>

int main(void)
{
    int i = 0;

    tracking:
        if (i == 0)
        {
            i++;
            goto print_star1;
        }
        else if (i == 1)
        {
            i++;
            goto print_star2;
        }
        else if (i == 2)
        {
            i++;
            goto print_star3;
        }
        else if (i == 3)
        {
            i++;
            goto print_star4;
        }
        else
        {
            goto print_star5;
        }

    print_star1:
        printf("    *    \n");
        goto tracking;

    print_star2:
        printf("   * *   \n");
        goto tracking;

    print_star3:
        printf("  *   *  \n");
        goto tracking;

    print_star4:
        printf(" *     * \n");
        goto tracking;

    print_star5:
        printf("*********\n");

    return 0;
}
