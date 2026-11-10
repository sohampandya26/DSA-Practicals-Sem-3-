# Practical 2: Annual Bonus using Structure

## Problem Statement
Employee details (ID, Name, Salary) are stored together; a function receiving a structure computes a 10% annual bonus.

## Concepts Used
struct, pass-by-value of a structure

## Approach
`calculateBonus(Employee e)` receives a copy of the structure and returns `salary * 0.10`.

## Complexity
| Time | Space |
|------|-------|
| O(n) for n employees | O(n) |

## How to Run
```bash
gcc -Wall -std=c11 -o employee_bonus employee_bonus.c
./employee_bonus < input.txt
```

## Sample Input (`input.txt`)
```
3
101
Amit Verma
50000
102
Priya Shah
75000.50
103
Rahul Mehta
42000
```

## Sample Output
```
Number of employees (1-50): 
Employee 1
  ID     :   Name   :   Salary : 
Employee 2
  ID     :   Name   :   Salary : 
Employee 3
  ID     :   Name   :   Salary : 
ID     Name                       Salary   Bonus(10%)
-----------------------------------------------------
101    Amit Verma               50000.00      5000.00
102    Priya Shah               75000.50      7500.05
103    Rahul Mehta              42000.00      4200.00
```
