/* 
    Author: Chen Liang
    Description: Write a program which will define a union
                    and then use this union to assign and
                    access its memebers
 */
#include <stdio.h>

union student
{
    char letter_grade;
    int rounded_grade;
    float exact_grade;
};

int main(void)
{
    union student var1, var2;

    var1.exact_grade = 40.5;
    var1.letter_grade = 'C';
    var1.rounded_grade = 41;

    printf("Union record 1 values:\n");
    printf("Exact grade: %.2f\n", var1.exact_grade);
    printf("Rounded grade: %d\n", var1.rounded_grade);
    printf("Letter grade: %c\n", var1.letter_grade);

    printf("\nUnion record 2 values:\n");
    var2.letter_grade = 'A';
    printf("Letter grade: %c\n", var2.letter_grade);

    var2.rounded_grade = 90;
    printf("Rounded grade: %d\n", var2.rounded_grade);

    var2.exact_grade = 90.4;
    printf("Exact grade: %.2f\n", var2.exact_grade);

    return 0;
}
