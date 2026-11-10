/*
 * Practical 10 : Find a book by ID on a shelf - Linear Search
 * Time: O(n) worst/average, O(1) best | Space: O(1)
 */
#include <stdio.h>

#define MAX_BOOKS 100

/* returns 1-based shelf position or -1 if not found */
int linearSearch(const int ids[], int n, int key, int *comparisons)
{
    *comparisons = 0;
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (ids[i] == key) return i + 1;
    }
    return -1;
}

int main(void)
{
    int ids[MAX_BOOKS], n, key, cmp;

    printf("Number of books on the shelf (1-%d): ", MAX_BOOKS);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_BOOKS) { printf("Invalid count.\n"); return 1; }

    printf("Enter the %d book IDs in shelf order:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &ids[i]);

    while (1) {
        printf("\nEnter book ID to search (-1 to stop): ");
        if (scanf("%d", &key) != 1 || key == -1) break;
        int pos = linearSearch(ids, n, key, &cmp);
        if (pos != -1) printf("Book %d found at position %d on the shelf (%d comparison(s)).\n", key, pos, cmp);
        else           printf("Book %d is not available (%d comparison(s)).\n", key, cmp);
    }
    printf("Done.\n");
    return 0;
}
