#include <stdio.h>

int main()
{
    char *str = "Jason 43";
    char name[10], title[10];
    int age = 0;
    int ret = 0;

    ret = sscanf(str, "%s %s %d", name, title, &age);

    printf("Name: %s\n", name);
    printf("Title: %s\n", title);
    printf("Age: %d\n", age);

    return 0;
}
