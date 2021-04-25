#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20

struct employee
{
    char *name;
    int hire_date;
    float salary;
};

int main(void)
{
    struct employee john = { .hire_date=30, .salary = 30000.00 };

    john.name = (char *)malloc(NAME_LENGTH);
    strncpy(john.name, "John", NAME_LENGTH);

    char name[NAME_LENGTH];
    int hire_date = 0;
    float salary = 0.0;

    printf("Enter a name: ");
    scanf("%s", name);
    printf("Enter the hire date: ");
    scanf("%d", &hire_date);
    printf("Enter the salary: ");
    scanf("%f", &salary);

    struct employee alice = {
        .hire_date = hire_date, .salary = salary
    };
    alice.name = (char *)malloc(NAME_LENGTH);
    strncpy(alice.name, name, sizeof(name));

    printf("Employ 1\nName: %s\nHire Date: %d\nSalary: %.2f\n",
                                                    john.name,
                                                    john.hire_date,
                                                    john.salary);

    printf("Employ 2\nName: %s\nHire Date: %d\nSalary: %.2f\n",
                                                    alice.name,
                                                    alice.hire_date,
                                                    alice.salary);

    return 0;
}
