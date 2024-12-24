#include <stdio.h>

int main()
{
    int ai_data[3] = { 100, 200, 300 };

    void *pv_data = &ai_data[1];

    pv_data += sizeof(int);

    printf("%d", *(int *)pv_data);

    return 0;
}
