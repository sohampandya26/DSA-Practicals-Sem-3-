# Practical 8: Tower of Hanoi

## Problem Statement
Print all moves to shift n disks from source rod to destination rod using an auxiliary rod, recursively.

## Concepts Used
Recursion

## Approach
`hanoi(n,src,dst,aux)`: move n-1 disks to aux, move disk n, move n-1 disks onto it. Moves = 2^n - 1.

## Complexity
| Time | Space |
|------|-------|
| O(2^n) | O(n) recursion depth |

## How to Run
```bash
gcc -Wall -std=c11 -o tower_of_hanoi tower_of_hanoi.c
./tower_of_hanoi < input.txt
```

## Sample Input (`input.txt`)
```
3
```

## Sample Output
```
Enter number of disks (1-20): 
Steps to move 3 disk(s) from rod A to rod C using rod B:

Move  1: disk 1 from A to C
Move  2: disk 2 from A to B
Move  3: disk 1 from C to B
Move  4: disk 3 from A to C
Move  5: disk 1 from B to A
Move  6: disk 2 from B to C
Move  7: disk 1 from A to C

Total moves = 7 (2^3 - 1)
```
