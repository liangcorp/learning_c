#include <stdio.h>
#include <stdlib.h>

struct employee
{
    char name[30];
    char date[15];
    float salary;
};

int main(void)
{
    /* Declare and initialization of structure variables */

    struct employee emp={"Mike", "7/16/2015", 76909.00f};

    printf("\n Name: %s", emp.name);
    printf("\n Hire Date: %s", emp.date);
    printf("\n Salary: %.2f\n", emp.salary);

    printf("\nEnter employee information: \n");
    printf("Name: ");
    scanf("%s", emp.name);

    printf("Hire Date: ");
    scanf("%s", emp.date);
    
    printf("Salary: ");
    scanf("%f", &emp.salary);

    printf("\n Name: %s", emp.name);
    printf("\n Hire Date: %s", emp.date);
    printf("\n Salary: %.2f\n", emp.salary);

    return 0;
}
