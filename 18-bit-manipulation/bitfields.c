#include <stdio.h>

/*
    | 000 | 0 | 0 | 0 | 00000000 | 000000000000000000 |
    |Unused|f1| f2| f3|  type    |       index        |
*/

struct packed_struct {
    int count;
    char c;

	unsigned int : 3; // padding
	unsigned int f1 : 1;
	unsigned int f2 : 1;
	unsigned int f3 : 1;
	unsigned int type : 8;
	unsigned int index : 18;
};

int main()
{
    struct packed_struct packed_data;

    unsigned int bit = packed_data.type = 7;

    unsigned int i = packed_data.index / 5 + 1;

    if (packed_data.f2) {
        printf("f2 is true\n");
    }

	return 0;
}
