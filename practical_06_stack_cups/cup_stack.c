/*
 * Practical 6 : Cup counter (capacity 5) using a Stack (array implementation)
 * Operations  : Add (push), Serve (pop), Check a cup, Replace a cup, Show all
 */
#include <stdio.h>

#define MAX_CUPS 5

typedef struct {
    int cups[MAX_CUPS];
    int top;            /* index of top cup, -1 when empty */
} Counter;

void init(Counter *c) { c->top = -1; }
int  isFull(const Counter *c)  { return c->top == MAX_CUPS - 1; }
int  isEmpty(const Counter *c) { return c->top == -1; }

void addCup(Counter *c, int id)
{
    if (isFull(c)) { printf("Counter is full (max %d cups). Cup %d not added.\n", MAX_CUPS, id); return; }
    c->cups[++c->top] = id;
    printf("Cup %d placed on top.\n", id);
}

void serveCup(Counter *c)
{
    if (isEmpty(c)) { printf("No cups left - cannot serve the customer.\n"); return; }
    printf("Served cup %d to the customer.\n", c->cups[c->top--]);
}

/* position 1 = topmost cup */
int validPos(const Counter *c, int pos) { return pos >= 1 && pos <= c->top + 1; }

void checkCup(const Counter *c, int pos)
{
    if (!validPos(c, pos)) { printf("No cup at position %d from the top.\n", pos); return; }
    printf("Cup at position %d from top: ID %d\n", pos, c->cups[c->top - (pos - 1)]);
}

void replaceCup(Counter *c, int pos, int newId)
{
    if (!validPos(c, pos)) { printf("No cup at position %d from the top.\n", pos); return; }
    int idx = c->top - (pos - 1);
    printf("Cracked cup %d at position %d replaced with cup %d.\n", c->cups[idx], pos, newId);
    c->cups[idx] = newId;
}

void showCups(const Counter *c)
{
    if (isEmpty(c)) { printf("Counter is empty.\n"); return; }
    printf("Cups (top to bottom):");
    for (int i = c->top; i >= 0; i--) printf(" %d", c->cups[i]);
    printf("\n");
}

int main(void)
{
    Counter c;
    int choice, id, pos;
    init(&c);

    do {
        printf("\n--- Cup Counter Menu ---\n1. Add a cup\n2. Serve a cup\n"
               "3. Check a cup\n4. Replace a cup\n5. Show all cups\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
        case 1: printf("Cup ID: ");              scanf("%d", &id);  addCup(&c, id); break;
        case 2: serveCup(&c); break;
        case 3: printf("Position from top: ");   scanf("%d", &pos); checkCup(&c, pos); break;
        case 4: printf("Position from top: ");   scanf("%d", &pos);
                printf("New cup ID: ");          scanf("%d", &id);  replaceCup(&c, pos, id); break;
        case 5: showCups(&c); break;
        case 0: printf("Goodbye!\n"); break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
