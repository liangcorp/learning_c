#include <stdio.h>

struct
{
    char *name;
    enum symbol_type type;
    union
    {
        int i;
        float f;
        char c;
    } data;
    
} table [entries];
