/*
 * Practical 8 : Tower of Hanoi using Recursion
 * Moves needed for n disks = 2^n - 1
 */
#include <stdio.h>

static long moveCount = 0;

void hanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 0) return;
    hanoi(n - 1, source, auxiliary, destination);        /* move n-1 disks out of the way   */
    printf("Move %2ld: disk %d from %c to %c\n", ++moveCount, n, source, destination);
    hanoi(n - 1, auxiliary, destination, source);        /* bring them on top of disk n     */
}

int main(void)
{
    int n;
    printf("Enter number of disks (1-20): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    printf("\nSteps to move %d disk(s) from rod A to rod C using rod B:\n\n", n);
    hanoi(n, 'A', 'C', 'B');
    printf("\nTotal moves = %ld (2^%d - 1)\n", moveCount, n);
    return 0;
}
