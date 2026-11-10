# Practical 6: Cup Counter - Stack

## Problem Statement
Counter holds max 5 cups, newest on top: add (push), serve (pop), check a cup at a position from top, replace a cup, show all.

## Concepts Used
Stack ADT (array implementation), overflow/underflow checks

## Approach
Array + `top` index. Position p from top maps to index `top-(p-1)`, so check/replace never disturb other cups.

## Complexity
| Time | Space |
|------|-------|
| Push/Pop O(1), check/replace O(1), show O(n) | O(1) (fixed size 5) |

## How to Run
```bash
gcc -Wall -std=c11 -o cup_stack cup_stack.c
./cup_stack < input.txt
```

## Sample Input (`input.txt`)
```
1
11
1
12
1
13
1
14
1
15
1
16
5
3
2
4
2
99
5
2
2
5
3
9
0
```

## Sample Output
```

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Cup ID: Cup 11 placed on top.

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Cup ID: Cup 12 placed on top.

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Cup ID: Cup 13 placed on top.

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Cup ID: Cup 14 placed on top.

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Cup ID: Cup 15 placed on top.

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Cup ID: Counter is full (max 5 cups). Cup 16 not added.

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Cups (top to bottom): 15 14 13 12 11

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Position from top: Cup at position 2 from top: ID 14

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Position from top: New cup ID: Cracked cup 14 at position 2 replaced with cup 99.

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Cups (top to bottom): 15 99 13 12 11

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Served cup 15 to the customer.

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Served cup 99 to the customer.

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Cups (top to bottom): 13 12 11

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Position from top: No cup at position 9 from the top.

--- Cup Counter Menu ---
1. Add a cup
2. Serve a cup
3. Check a cup
4. Replace a cup
5. Show all cups
0. Exit
Choice: Goodbye!
```
