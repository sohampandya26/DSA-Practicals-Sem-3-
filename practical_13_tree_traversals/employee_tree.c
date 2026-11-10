/*
 * Practical 13 : Company hierarchy as a tree + traversals
 *
 * Part A - General tree (a manager can have many subordinates)
 *          stored with the "first child / next sibling" representation
 *            1. Preorder  : visit manager BEFORE subordinates
 *            2. Postorder : visit subordinates BEFORE manager
 * Part B - Binary hierarchy (max two subordinates: left & right)
 *            Inorder   : left subordinate, manager, right subordinate
 *            Preorder / Postorder as well
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Part A : general tree ---------- */
typedef struct GNode {
    char name[30], title[25];
    struct GNode *firstChild, *nextSibling;
} GNode;

GNode *newG(const char *name, const char *title)
{
    GNode *n = (GNode *)calloc(1, sizeof(GNode));
    if (!n) { printf("Out of memory!\n"); exit(1); }
    strncpy(n->name, name, sizeof n->name - 1);
    strncpy(n->title, title, sizeof n->title - 1);
    return n;
}

void addSubordinate(GNode *manager, GNode *emp)
{
    if (!manager->firstChild) { manager->firstChild = emp; return; }
    GNode *t = manager->firstChild;
    while (t->nextSibling) t = t->nextSibling;
    t->nextSibling = emp;
}

void preorderG(const GNode *r, int depth)
{
    for (; r; r = r->nextSibling) {
        printf("%*s%s (%s)\n", depth * 4, "", r->name, r->title);   /* manager first */
        preorderG(r->firstChild, depth + 1);
    }
}

void postorderG(const GNode *r, int depth)
{
    for (; r; r = r->nextSibling) {
        postorderG(r->firstChild, depth + 1);                        /* subordinates first */
        printf("%*s%s (%s)\n", depth * 4, "", r->name, r->title);
    }
}

void freeG(GNode *r)
{
    while (r) { GNode *nx = r->nextSibling; freeG(r->firstChild); free(r); r = nx; }
}

/* ---------- Part B : binary hierarchy ---------- */
typedef struct BNode {
    char name[30];
    struct BNode *left, *right;
} BNode;

BNode *newB(const char *name, BNode *l, BNode *r)
{
    BNode *n = (BNode *)calloc(1, sizeof(BNode));
    if (!n) { printf("Out of memory!\n"); exit(1); }
    strncpy(n->name, name, sizeof n->name - 1);
    n->left = l; n->right = r;
    return n;
}

void inorderB(const BNode *r)   { if (!r) return; inorderB(r->left);  printf("%s ", r->name); inorderB(r->right); }
void preorderB(const BNode *r)  { if (!r) return; printf("%s ", r->name); preorderB(r->left); preorderB(r->right); }
void postorderB(const BNode *r) { if (!r) return; postorderB(r->left); postorderB(r->right); printf("%s ", r->name); }
void freeB(BNode *r)            { if (!r) return; freeB(r->left); freeB(r->right); free(r); }

int main(void)
{
    /* ----- Part A ----- */
    GNode *ceo = newG("Aditi Sharma", "CEO");
    GNode *cto = newG("Rohan Mehta", "CTO");
    GNode *cfo = newG("Neha Gupta", "CFO");
    GNode *coo = newG("Vikram Singh", "COO");
    GNode *dev = newG("Karan Patel", "Dev Lead");
    GNode *qa  = newG("Simran Kaur", "QA Lead");
    GNode *acc = newG("Manish Joshi", "Accountant");

    addSubordinate(ceo, cto); addSubordinate(ceo, cfo); addSubordinate(ceo, coo);
    addSubordinate(cto, dev); addSubordinate(cto, qa);
    addSubordinate(cfo, acc);
    addSubordinate(dev, newG("Ankit Rana", "Developer"));
    addSubordinate(dev, newG("Pooja Nair", "Developer"));

    printf("=== Part A: General company tree ===\n\n");
    printf("1. Preorder (manager before subordinates):\n");
    preorderG(ceo, 0);
    printf("\n2. Postorder (subordinates before manager):\n");
    postorderG(ceo, 0);

    /* ----- Part B ----- */
    /*            CEO
     *          /     \
     *        M1       M2
     *       /  \     /  \
     *      A    B   C    D        */
    BNode *root = newB("CEO",
                       newB("M1", newB("A", NULL, NULL), newB("B", NULL, NULL)),
                       newB("M2", newB("C", NULL, NULL), newB("D", NULL, NULL)));

    printf("\n=== Part B: Binary hierarchy ===\n");
    printf("Inorder   (left, manager, right)       : "); inorderB(root);   printf("\n");
    printf("Preorder  (manager, left, right)       : "); preorderB(root);  printf("\n");
    printf("Postorder (subordinates before manager): "); postorderB(root); printf("\n");

    freeG(ceo);
    freeB(root);
    return 0;
}
