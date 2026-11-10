/*
 * Practical 12 : Hospital patient IDs in a Binary Search Tree
 * smaller IDs -> left, larger IDs -> right
 * Insert/Search: O(log n) average, O(n) worst case (skewed tree)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node *left, *right;
} Node;

Node *newNode(int id)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) { printf("Out of memory!\n"); exit(1); }
    n->id = id;
    n->left = n->right = NULL;
    return n;
}

Node *insert(Node *root, int id, int *duplicate)
{
    if (!root) return newNode(id);
    if (id < root->id)      root->left  = insert(root->left,  id, duplicate);
    else if (id > root->id) root->right = insert(root->right, id, duplicate);
    else                    *duplicate = 1;
    return root;
}

/* returns number of nodes visited; sets *found */
int search(const Node *root, int id, int *found)
{
    int visited = 0;
    *found = 0;
    while (root) {
        visited++;
        if (id == root->id) { *found = 1; break; }
        root = (id < root->id) ? root->left : root->right;
    }
    return visited;
}

void inorder(const Node *r)
{
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->id);
    inorder(r->right);
}

int height(const Node *r)
{
    if (!r) return 0;
    int l = height(r->left), rt = height(r->right);
    return 1 + (l > rt ? l : rt);
}

void freeTree(Node *r)
{
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    free(r);
}

int main(void)
{
    Node *root = NULL;
    int choice, id, dup, found, visited;

    do {
        printf("\n--- Patient BST Menu ---\n1. Insert patient ID\n2. Search patient ID\n"
               "3. Display IDs in sorted order (inorder)\n4. Tree height\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
        case 1:
            printf("Patient ID: "); scanf("%d", &id);
            dup = 0;
            root = insert(root, id, &dup);
            printf(dup ? "ID %d already exists.\n" : "ID %d inserted.\n", id);
            break;
        case 2:
            printf("Patient ID to search: "); scanf("%d", &id);
            visited = search(root, id, &found);
            if (found) printf("Patient %d found (visited %d node(s)).\n", id, visited);
            else       printf("Patient %d not found (visited %d node(s)).\n", id, visited);
            break;
        case 3:
            if (!root) printf("No records.\n");
            else { printf("Sorted IDs: "); inorder(root); printf("\n"); }
            break;
        case 4: printf("Height of tree = %d\n", height(root)); break;
        case 0: printf("Goodbye!\n"); break;
        default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    freeTree(root);
    return 0;
}
