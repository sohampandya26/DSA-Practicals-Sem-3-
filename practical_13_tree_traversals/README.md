# Practical 13: Company Hierarchy - Tree Traversals

## Problem Statement
Represent a company hierarchy as a tree and traverse it: manager before subordinates, left-manager-right for binary hierarchy, subordinates before manager.

## Concepts Used
General tree (first-child/next-sibling), binary tree, preorder/inorder/postorder

## Approach
Part A: general tree with preorder and postorder (indented output). Part B: binary hierarchy with inorder, preorder, postorder.

## Complexity
| Time | Space |
|------|-------|
| O(n) per traversal | O(h) recursion stack |

## How to Run
```bash
gcc -Wall -std=c11 -o employee_tree employee_tree.c
./employee_tree
```

## Sample Output
```
=== Part A: General company tree ===

1. Preorder (manager before subordinates):
Aditi Sharma (CEO)
    Rohan Mehta (CTO)
        Karan Patel (Dev Lead)
            Ankit Rana (Developer)
            Pooja Nair (Developer)
        Simran Kaur (QA Lead)
    Neha Gupta (CFO)
        Manish Joshi (Accountant)
    Vikram Singh (COO)

2. Postorder (subordinates before manager):
            Ankit Rana (Developer)
            Pooja Nair (Developer)
        Karan Patel (Dev Lead)
        Simran Kaur (QA Lead)
    Rohan Mehta (CTO)
        Manish Joshi (Accountant)
    Neha Gupta (CFO)
    Vikram Singh (COO)
Aditi Sharma (CEO)

=== Part B: Binary hierarchy ===
Inorder   (left, manager, right)       : A M1 B CEO C M2 D 
Preorder  (manager, left, right)       : CEO M1 A B M2 C D 
Postorder (subordinates before manager): A B M1 C D M2 CEO
```
