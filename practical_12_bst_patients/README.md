# Practical 12: Patient IDs - Binary Search Tree

## Problem Statement
Smaller IDs to the left, larger to the right; insert new IDs and search by ID.

## Concepts Used
BST, recursion, dynamic memory

## Approach
Insert by comparing with the root recursively (duplicates rejected); iterative search reports nodes visited; inorder gives sorted IDs; height shown.

## Complexity
| Time | Space |
|------|-------|
| Average O(log n), worst O(n) | O(n) |

## How to Run
```bash
gcc -Wall -std=c11 -o bst_patients bst_patients.c
./bst_patients < input.txt
```

## Sample Input (`input.txt`)
```
1
50
1
30
1
70
1
20
1
40
1
60
1
80
1
30
3
4
2
60
2
65
0
```

## Sample Output
```

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Patient ID: ID 50 inserted.

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Patient ID: ID 30 inserted.

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Patient ID: ID 70 inserted.

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Patient ID: ID 20 inserted.

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Patient ID: ID 40 inserted.

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Patient ID: ID 60 inserted.

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Patient ID: ID 80 inserted.

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Patient ID: ID 30 already exists.

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Sorted IDs: 20 30 40 50 60 70 80 

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Height of tree = 3

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Patient ID to search: Patient 60 found (visited 3 node(s)).

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Patient ID to search: Patient 65 not found (visited 3 node(s)).

--- Patient BST Menu ---
1. Insert patient ID
2. Search patient ID
3. Display IDs in sorted order (inorder)
4. Tree height
0. Exit
Choice: Goodbye!
```
