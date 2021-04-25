#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 10

struct p_names
{
    char *f_name;
    char *l_name;
    int letters;
};

void get_info(struct p_names pst)
{
    char temp[SLEN];
    printf("Please enter your first name.\n");
    fgets(temp, SLEN, stdin);

    // allocate memory to hold name
    pst.f_name = (char *)malloc(strlen(temp) + 1);

    // Copy name to allocated memory
    strcpy(pst.f_name, temp);

    printf("Please enter your last name.\n");

    fgets(temp, SLEN, stdin);
    pst.l_name = (char *)malloc(strlen(temp) + 1);
    strcpy(pst.l_name, temp);

    printf("%s %s", pst.f_name, pst.l_name);

    free(pst.f_name);
    free(pst.l_name);
}

int main(void)
{
    struct p_names name;
    get_info(name);

    return 0;
}
