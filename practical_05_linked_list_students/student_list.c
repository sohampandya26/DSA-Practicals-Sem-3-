/*
 * Practical 5 : Dynamic student list using a Singly Linked List
 * Operations  : Insert at beginning / middle / end, Delete, Display, Search
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int roll;
    struct Node *next;
} Node;

static Node *createNode(int roll)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed!\n"); exit(1); }
    n->roll = roll;
    n->next = NULL;
    return n;
}

/* returns position (1-based) of roll or 0 if absent */
int searchStudent(const Node *head, int roll)
{
    int pos = 1;
    for (; head; head = head->next, pos++)
        if (head->roll == roll) return pos;
    return 0;
}

Node *insertBeginning(Node *head, int roll)
{
    Node *n = createNode(roll);
    n->next = head;
    return n;
}

Node *insertEnd(Node *head, int roll)
{
    Node *n = createNode(roll);
    if (!head) return n;
    Node *t = head;
    while (t->next) t = t->next;
    t->next = n;
    return head;
}

/* Insert so that the new student becomes the pos-th node (1-based).
   If pos is larger than the list, it is added at the end. */
Node *insertAtPosition(Node *head, int roll, int pos)
{
    if (pos <= 1 || !head) return insertBeginning(head, roll);
    Node *t = head;
    for (int i = 1; i < pos - 1 && t->next; i++) t = t->next;
    Node *n = createNode(roll);
    n->next = t->next;
    t->next = n;
    return head;
}

Node *removeStudent(Node *head, int roll, int *removed)
{
    *removed = 0;
    if (!head) return NULL;
    if (head->roll == roll) {
        Node *t = head->next;
        free(head);
        *removed = 1;
        return t;
    }
    Node *p = head;
    while (p->next && p->next->roll != roll) p = p->next;
    if (p->next) {
        Node *d = p->next;
        p->next = d->next;
        free(d);
        *removed = 1;
    }
    return head;
}

void display(const Node *head)
{
    if (!head) { printf("List is empty.\n"); return; }
    printf("Enrolled students: ");
    for (; head; head = head->next)
        printf("%d%s", head->roll, head->next ? " -> " : " -> NULL\n");
}

void freeList(Node *head)
{
    while (head) { Node *t = head; head = head->next; free(t); }
}

int main(void)
{
    Node *head = NULL;
    int choice, roll, pos, removed;

    do {
        printf("\n--- Student List Menu ---\n"
               "1. Add at beginning\n2. Add at a position (middle)\n3. Add at end\n"
               "4. Remove student (admission cancel)\n5. Display all\n"
               "6. Search by roll number\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice >= 1 && choice <= 3) {
            printf("Roll number: ");
            scanf("%d", &roll);
            if (searchStudent(head, roll)) {
                printf("Roll number %d already exists (must be unique).\n", roll);
                continue;
            }
            if (choice == 1) head = insertBeginning(head, roll);
            else if (choice == 3) head = insertEnd(head, roll);
            else {
                printf("Position (1-based): ");
                scanf("%d", &pos);
                head = insertAtPosition(head, roll, pos);
            }
            printf("Student %d added.\n", roll);
        } else if (choice == 4) {
            printf("Roll number to remove: ");
            scanf("%d", &roll);
            head = removeStudent(head, roll, &removed);
            printf(removed ? "Student %d removed.\n" : "Student %d not found.\n", roll);
        } else if (choice == 5) {
            display(head);
        } else if (choice == 6) {
            printf("Roll number to search: ");
            scanf("%d", &roll);
            pos = searchStudent(head, roll);
            if (pos) printf("Student %d found at position %d.\n", roll, pos);
            else     printf("Student %d not found.\n", roll);
        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    freeList(head);
    return 0;
}
