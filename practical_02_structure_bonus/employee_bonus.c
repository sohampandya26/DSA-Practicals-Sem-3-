/*
 * Practical 2 : Annual bonus using a structure passed to a function
 * Concepts    : struct, passing a structure by value
 */
#include <stdio.h>

#define MAX_EMP 50

typedef struct {
    int    id;
    char   name[50];
    double salary;
} Employee;

/* Structure is passed BY VALUE; bonus is 10% of salary */
double calculateBonus(Employee e)
{
    return e.salary * 0.10;
}

int main(void)
{
    Employee emp[MAX_EMP];
    int n;

    printf("Number of employees (1-%d): ", MAX_EMP);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_EMP) {
        printf("Invalid count.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d\n  ID     : ", i + 1);
        scanf("%d", &emp[i].id);
        printf("  Name   : ");
        scanf(" %49[^\n]", emp[i].name);
        printf("  Salary : ");
        scanf("%lf", &emp[i].salary);
    }

    printf("\n%-6s %-20s %12s %12s\n", "ID", "Name", "Salary", "Bonus(10%)");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-6d %-20s %12.2f %12.2f\n", emp[i].id, emp[i].name,
               emp[i].salary, calculateBonus(emp[i]));
    return 0;
}
