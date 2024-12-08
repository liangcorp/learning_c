#include <stdio.h>
#include <malloc.h>

/*
    A flexible array memeber can be declared only as the last member of struct
    Each struct can contain at most 1 flexible array memeber
    A flexible array can NOT be the only member of a struct
    Any struct containing a flexible array member cannot be a member of another struct
    A struct with a flexible array member can NOT be statically initialized
        - It must be allocated dynamically
        - You can NOT fix the size of the flexible array member at compile time
*/

struct s {
    int array_size;
    int array[];
};

int main()
{
    int desired_size = 5;
    struct s *ptr = NULL;

    ptr = malloc(sizeof(struct s) + desired_size * sizeof(int));

    free(ptr);
    ptr = NULL;

    return 0;
}
