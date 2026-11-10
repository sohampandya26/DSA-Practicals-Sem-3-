/*
 * Practical 1 : Find the topper of a class
 * Concepts    : Arrays, passing an array to a function
 */
#include <stdio.h>

#define STUDENTS 10

/* Returns the highest value present in marks[0..n-1] */
int findTopper(const int marks[], int n)
{
    int top = marks[0];
    for (int i = 1; i < n; i++)
        if (marks[i] > top)
            top = marks[i];
    return top;
}

int main(void)
{
    int marks[STUDENTS];

    printf("Enter the marks (0-100) of %d students:\n", STUDENTS);
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student %2d: ", i + 1);
        if (scanf("%d", &marks[i]) != 1 || marks[i] < 0 || marks[i] > 100) {
            printf("\nInvalid input. Marks must be an integer between 0 and 100.\n");
            return 1;
        }
    }

    int top = findTopper(marks, STUDENTS);
    printf("\nHighest marks (topper): %d\n", top);
    printf("Scored by student number(s):");
    for (int i = 0; i < STUDENTS; i++)
        if (marks[i] == top)
            printf(" %d", i + 1);
    printf("\n");
    return 0;
}
