# Practical 15: Sorting Algorithms Case Study

## Problem Statement
Compare Bubble, Selection, Insertion, Merge and Quick sort on five arrays (A1-A5) and interpret the results.

## Concepts Used
Sorting, time measurement, best/average/worst cases

## Approach
Each algorithm sorts a fresh copy of each array; time is averaged over many repetitions, comparisons are counted, results go to `results.csv`. Fixed random seed gives reproducible data.

## Complexity
| Time | Space |
|------|-------|
| Bubble/Selection/Insertion O(n^2); Merge O(n log n); Quick O(n log n) avg, O(n^2) worst | Merge O(n); others O(1) (Quick O(log n) stack avg) |

## How to Run
```bash
gcc -Wall -std=c11 -o sorting_study sorting_study.c
./sorting_study
```

## Sample Output
```
Sorting algorithm comparison (ascending order)
Time = average over repetitions, Comparisons = key comparisons made

A1 - Small random (n=10)
Algorithm       Time (us)    Comparisons
-------------------------------------------
Bubble               0.18             45
Selection            0.14             45
Insertion            0.05             33
Merge                0.11             24
Quick                0.06             31
Fastest: Insertion

A2 - Medium random (n=100)
Algorithm       Time (us)    Comparisons
-------------------------------------------
Bubble              16.93           4944
Selection           12.61           4950
Insertion            1.35           2668
Merge                1.32            553
Quick                0.66            736
Fastest: Quick

A3 - Large random (n=1000)
Algorithm       Time (us)    Comparisons
-------------------------------------------
Bubble            1775.46         498419
Selection         1211.99         499500
Insertion          127.15         257842
Merge               35.33           8705
...
```
