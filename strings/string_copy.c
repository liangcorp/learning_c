#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "My name is Chen";
    char temp[50];
    
    strncpy(temp, s, sizeof(temp) - 1);

    printf("The length of 's' is: %d\n", strlen(s));
    printf("The temp is %s\n", temp);
    return 0;
}