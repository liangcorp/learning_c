#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = NULL;

    fp = fopen("myfile.txt", "w+");
    if (fp != NULL)
        fprintf(fp, "%s %s %s %s %d", "Hello", "my", "number", "is", 555);

    fclose(fp);

    return 0;
}
