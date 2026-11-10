/*
 * Practical 9 : Ice-cream truck line (max 5 kids) using a Circular Queue
 * Operations  : Join line (enqueue), Serve (dequeue), Next kid (front), Show line
 */
#include <stdio.h>

#define MAX_KIDS 5
#define NAME_LEN 30

typedef struct {
    char names[MAX_KIDS][NAME_LEN];
    int  front, rear, count;
} Queue;

void init(Queue *q) { q->front = 0; q->rear = -1; q->count = 0; }

void joinLine(Queue *q, const char *name)
{
    if (q->count == MAX_KIDS) { printf("Line is full! %s cannot join.\n", name); return; }
    q->rear = (q->rear + 1) % MAX_KIDS;
    int i = 0;
    for (; name[i] && i < NAME_LEN - 1; i++) q->names[q->rear][i] = name[i];
    q->names[q->rear][i] = '\0';
    q->count++;
    printf("%s joined the line.\n", name);
}

void serve(Queue *q)
{
    if (q->count == 0) { printf("Nobody is waiting.\n"); return; }
    printf("Served ice cream to %s. Enjoy!\n", q->names[q->front]);
    q->front = (q->front + 1) % MAX_KIDS;
    q->count--;
}

void nextKid(const Queue *q)
{
    if (q->count == 0) printf("Nobody is waiting.\n");
    else printf("Next to be served: %s\n", q->names[q->front]);
}

void showLine(const Queue *q)
{
    if (q->count == 0) { printf("Line is empty.\n"); return; }
    printf("Line (front to back):");
    for (int i = 0, idx = q->front; i < q->count; i++, idx = (idx + 1) % MAX_KIDS)
        printf(" %s%s", q->names[idx], i < q->count - 1 ? " <-" : "");
    printf("\n");
}

int main(void)
{
    Queue q;
    int choice;
    char name[NAME_LEN];
    init(&q);

    do {
        printf("\n--- Ice Cream Truck Menu ---\n1. Join line\n2. Serve ice cream\n"
               "3. Next kid\n4. Show line\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
        case 1: printf("Kid's name: "); scanf(" %29[^\n]", name); joinLine(&q, name); break;
        case 2: serve(&q);    break;
        case 3: nextKid(&q);  break;
        case 4: showLine(&q); break;
        case 0: printf("Goodbye!\n"); break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}
