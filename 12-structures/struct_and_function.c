#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Family {
    char name[20];
    int age;
    char father[20];
    char mother[20];
};

bool siblings(struct Family member1, struct Family member2)
{
    if (strcmp(member1.mother, member2.mother) == 0)
        return true;
    else
        return false;
}

bool siblings_ptr(struct Family *member1, struct Family *member2)
{
    if (strcmp(member1->mother, member2->mother) == 0)
        return true;
    else
        return false;
}

int main()
{
    printf("\n");

    return 0;
}
