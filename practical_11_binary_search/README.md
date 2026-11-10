# Practical 11: Guest List Check - Binary Search

## Problem Statement
Guests sorted alphabetically; check an arriving guest without checking every name.

## Concepts Used
Binary search on strings, `strcmp`-style comparison

## Approach
Halve the search range each step (case-insensitive compare). Prints position and number of steps. Requires sorted data.

## Complexity
| Time | Space |
|------|-------|
| O(log n) | O(1) |

## How to Run
```bash
gcc -Wall -std=c11 -o guest_search guest_search.c
./guest_search < input.txt
```

## Sample Input (`input.txt`)
```
Meera Joshi
Zoya Ali
ishaan malhotra
Aarav Shah
exit
```

## Sample Output
```
Guest list (sorted):
 1. Aarav Shah
 2. Ananya Iyer
 3. Bhavya Patel
 4. Chirag Desai
 5. Deepak Rao
 6. Esha Kapoor
 7. Farhan Khan
 8. Gauri Nair
 9. Harsh Vora
10. Ishaan Malhotra
11. Jaya Menon
12. Kunal Mehta
13. Meera Joshi
14. Nikhil Sharma
15. Riya Singh

Enter guest name (or 'exit'): Welcome! Meera Joshi is at position 13 (found in 4 step(s)).

Enter guest name (or 'exit'): Guest not invited (checked in 4 step(s)).

Enter guest name (or 'exit'): Welcome! Ishaan Malhotra is at position 10 (found in 3 step(s)).

Enter guest name (or 'exit'): Welcome! Aarav Shah is at position 1 (found in 4 step(s)).

Enter guest name (or 'exit'): Event check-in closed.
```
