#include <stdio.h>

union student
{
    char letter_grade;
    int rounded_grade;
    float exact_grade;
};

int main()
{
    union student one = { .rounded_grade = 6 };
    union student two;

    printf("Letter grade: %c\n", one.letter_grade);
    printf("Rounded grade: %d\n", one.rounded_grade);
    printf("Exact grade: %f\n", one.exact_grade);
    printf("\n");

    two.letter_grade = 'A';
    printf("Letter grade: %c\n", two.letter_grade);
    printf("Rounded grade: %d\n", two.rounded_grade);
    printf("Exact grade: %f\n", two.exact_grade);
    printf("\n");

    two.rounded_grade = 90;
    printf("Letter grade: %c\n", two.letter_grade);
    printf("Rounded grade: %d\n", two.rounded_grade);
    printf("Exact grade: %f\n", two.exact_grade);
    printf("\n");

    two.exact_grade = 90.5;
    printf("Letter grade: %c\n", two.letter_grade);
    printf("Rounded grade: %d\n", two.rounded_grade);
    printf("Exact grade: %f\n", two.exact_grade);
    printf("\n");

    return 0;
}
