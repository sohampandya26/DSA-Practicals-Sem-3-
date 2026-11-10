# Practical 1: Find the Topper

## Problem Statement
Teacher gives marks of 10 students; pass them to `findTopper()` which returns the highest marks.

## Concepts Used
Arrays, functions, passing arrays

## Approach
Linear scan keeping a running maximum; also reports which student(s) scored it.

## Complexity
| Time | Space |
|------|-------|
| O(n) | O(1) |

## How to Run
```bash
gcc -Wall -std=c11 -o find_topper find_topper.c
./find_topper < input.txt
```

## Sample Input (`input.txt`)
```
45 89 67 92 78 56 88 73 95 61
```

## Sample Output
```
Enter the marks (0-100) of 10 students:
Student  1: Student  2: Student  3: Student  4: Student  5: Student  6: Student  7: Student  8: Student  9: Student 10: 
Highest marks (topper): 95
Scored by student number(s): 9
```
