# Practical 3: Library Book Records

## Problem Statement
Store title, author and price of 5 books and display every book priced above Rs. 500.

## Concepts Used
Array of structures

## Approach
Read 5 `Book` records, print all, then filter with `price > 500`.

## Complexity
| Time | Space |
|------|-------|
| O(n) | O(n) |

## How to Run
```bash
gcc -Wall -std=c11 -o library_books library_books.c
./library_books < input.txt
```

## Sample Input (`input.txt`)
```
Let Us C
Yashavant Kanetkar
350
Data Structures Using C
Reema Thareja
625.50
Introduction to Algorithms
Thomas H. Cormen
1250
The C Programming Language
Kernighan and Ritchie
480
Data Structures and Algorithms Made Easy
Narasimha Karumanchi
799
```

## Sample Output
```
Book 1
  Title  :   Author :   Price  : Book 2
  Title  :   Author :   Price  : Book 3
  Title  :   Author :   Price  : Book 4
  Title  :   Author :   Price  : Book 5
  Title  :   Author :   Price  : 
=== All books ===
No  Title                          Author                  Price
1   Let Us C                       Yashavant Kanetkar     350.00
2   Data Structures Using C        Reema Thareja          625.50
3   Introduction to Algorithms     Thomas H. Cormen      1250.00
4   The C Programming Language     Kernighan and Ritchie   480.00
5   Data Structures and Algorithms Made Easy Narasimha Karumanchi   799.00

=== Books with price greater than Rs. 500 ===
Data Structures Using C        Reema Thareja        Rs. 625.50
Introduction to Algorithms     Thomas H. Cormen     Rs. 1250.00
Data Structures and Algorithms Made Easy Narasimha Karumanchi Rs. 799.00
```
