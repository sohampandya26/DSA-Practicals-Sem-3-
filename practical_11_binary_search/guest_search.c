/*
 * Practical 11 : Check whether a guest is invited - Binary Search on a sorted list
 * Time: O(log n) | Space: O(1)   (list MUST be sorted alphabetically)
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GUESTS   15
#define NAME_LEN 40

/* case-insensitive comparison so "meera joshi" matches "Meera Joshi" */
static int compareNames(const char *a, const char *b)
{
    while (*a && *b) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d) return d;
        a++; b++;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

/* returns 1-based position or -1 */
int binarySearch(const char list[][NAME_LEN], int n, const char *key, int *steps)
{
    int low = 0, high = n - 1;
    *steps = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        (*steps)++;
        int c = compareNames(key, list[mid]);
        if (c == 0) return mid + 1;
        if (c < 0) high = mid - 1;
        else       low  = mid + 1;
    }
    return -1;
}

int main(void)
{
    const char guests[GUESTS][NAME_LEN] = {
        "Aarav Shah", "Ananya Iyer", "Bhavya Patel", "Chirag Desai", "Deepak Rao",
        "Esha Kapoor", "Farhan Khan", "Gauri Nair", "Harsh Vora", "Ishaan Malhotra",
        "Jaya Menon", "Kunal Mehta", "Meera Joshi", "Nikhil Sharma", "Riya Singh"
    };
    char name[NAME_LEN];
    int steps;

    printf("Guest list (sorted):\n");
    for (int i = 0; i < GUESTS; i++) printf("%2d. %s\n", i + 1, guests[i]);

    while (1) {
        printf("\nEnter guest name (or 'exit'): ");
        if (!fgets(name, sizeof name, stdin)) break;
        name[strcspn(name, "\n")] = '\0';
        if (compareNames(name, "exit") == 0) break;
        if (name[0] == '\0') continue;

        int pos = binarySearch(guests, GUESTS, name, &steps);
        if (pos != -1) printf("Welcome! %s is at position %d (found in %d step(s)).\n", guests[pos - 1], pos, steps);
        else           printf("Guest not invited (checked in %d step(s)).\n", steps);
    }
    printf("Event check-in closed.\n");
    return 0;
}
