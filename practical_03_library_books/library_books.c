/*
 * Practical 3 : Library record - display books costing more than Rs. 500
 * Concepts    : Array of structures
 */
#include <stdio.h>

#define BOOKS 5
#define PRICE_LIMIT 500.0

typedef struct {
    char   title[100];
    char   author[60];
    double price;
} Book;

int main(void)
{
    Book lib[BOOKS];

    for (int i = 0; i < BOOKS; i++) {
        printf("Book %d\n  Title  : ", i + 1);
        scanf(" %99[^\n]", lib[i].title);
        printf("  Author : ");
        scanf(" %59[^\n]", lib[i].author);
        printf("  Price  : ");
        scanf("%lf", &lib[i].price);
    }

    printf("\n=== All books ===\n");
    printf("%-3s %-30s %-20s %8s\n", "No", "Title", "Author", "Price");
    for (int i = 0; i < BOOKS; i++)
        printf("%-3d %-30s %-20s %8.2f\n", i + 1, lib[i].title, lib[i].author, lib[i].price);

    printf("\n=== Books with price greater than Rs. %.0f ===\n", PRICE_LIMIT);
    int found = 0;
    for (int i = 0; i < BOOKS; i++) {
        if (lib[i].price > PRICE_LIMIT) {
            printf("%-30s %-20s Rs. %.2f\n", lib[i].title, lib[i].author, lib[i].price);
            found++;
        }
    }
    if (!found)
        printf("No book costs more than Rs. %.0f.\n", PRICE_LIMIT);
    return 0;
}
