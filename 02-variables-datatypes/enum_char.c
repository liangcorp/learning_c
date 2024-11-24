#include <stdio.h>

int main()
{
	enum gender {
        male,
        female
	};

	enum gender sex = male;

	printf("The sex is %d\n", sex);

	char broiled;
	broiled = 'T';

    printf("My charactor: %c\n", broiled);

	return 0;
}
