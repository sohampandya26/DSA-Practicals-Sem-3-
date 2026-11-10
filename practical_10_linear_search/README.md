# Practical 10: Find a Book by ID - Linear Search

## Problem Statement
Check books one by one from the first until the ID is found; report position or not available.

## Concepts Used
Linear (sequential) search

## Approach
Scan left to right, counting comparisons. Works on unsorted data.

## Complexity
| Time | Space |
|------|-------|
| O(n) (best O(1)) | O(1) |

## How to Run
```bash
gcc -Wall -std=c11 -o linear_search linear_search.c
./linear_search < input.txt
```

## Sample Input (`input.txt`)
```
8
204 117 309 45 512 88 631 250
512
204
999
-1
```

## Sample Output
```
Number of books on the shelf (1-100): Enter the 8 book IDs in shelf order:

Enter book ID to search (-1 to stop): Book 512 found at position 5 on the shelf (5 comparison(s)).

Enter book ID to search (-1 to stop): Book 204 found at position 1 on the shelf (1 comparison(s)).

Enter book ID to search (-1 to stop): Book 999 is not available (8 comparison(s)).

Enter book ID to search (-1 to stop): Done.
```
