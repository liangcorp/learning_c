#include <stdio.h>

struct owner
{

};

struct leasecompany
{

};

struct car_data
{
    char make[15];
    int status;
    union {
        struct owner ownercar;
        struct leasecompany leasecar;
    };
};

enum symbolType P

};

struct {
    char *name;
    enum symbolType type;
    union {
        int i;
        float f;
        char c;
    } data;
} table[entries];

