#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 0;
    printf("Entering the size of string: ");
    scanf("%d", &size);

    char *str = NULL;
    str = (char *)malloc((size + 1) * sizeof(char));

    if (str == NULL)
        return 1;

    printf("Enter the string: ");
    scanf("%s",  str);

    printf("%s\n", str);

    free(str);
    str = NULL;

    return 0;
}
