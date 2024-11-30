#include <stdio.h>
#include <string.h>

struct employee {
	char name[100];
	int id;
	float salary;
};

int main()
{
	struct employee bob;

	strncpy(bob.name, "Bob", 4);
	bob.id = 30;
	bob.salary = 1000.0;

	struct employee second;
	printf("Enter employ name: ");
	scanf("%s", second.name);
	printf("Enter employ hire date: ");
	scanf("%d", &second.id);
	printf("Enter employ salary: ");
	scanf("%f", &second.salary);

	printf("Bob's name: %s\n, ID: %d\n, and salary: %f\n", bob.name, bob.id,
	       bob.salary);

	printf("Second Employ's name: %s\n, ID: %d\n, and salary: %f\n",
	       second.name, second.id, second.salary);
}
