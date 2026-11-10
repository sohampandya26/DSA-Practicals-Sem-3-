# Practical 9: Ice Cream Truck - Queue

## Problem Statement
Only 5 kids can wait. Join line, serve first kid, see next kid, show line.

## Concepts Used
Queue ADT, circular queue (array)

## Approach
FIFO with `front`, `rear`, `count` and modulo arithmetic so freed slots are reused.

## Complexity
| Time | Space |
|------|-------|
| Enqueue/Dequeue/Peek O(1), show O(n) | O(1) (fixed size 5) |

## How to Run
```bash
gcc -Wall -std=c11 -o icecream_queue icecream_queue.c
./icecream_queue < input.txt
```

## Sample Input (`input.txt`)
```
1
Aarav
1
Diya
1
Kabir
1
Mira
1
Neel
1
Om
4
3
2
2
4
1
Om
4
0
```

## Sample Output
```

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Kid's name: Aarav joined the line.

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Kid's name: Diya joined the line.

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Kid's name: Kabir joined the line.

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Kid's name: Mira joined the line.

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Kid's name: Neel joined the line.

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Kid's name: Line is full! Om cannot join.

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Line (front to back): Aarav <- Diya <- Kabir <- Mira <- Neel

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Next to be served: Aarav

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Served ice cream to Aarav. Enjoy!

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Served ice cream to Diya. Enjoy!

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Line (front to back): Kabir <- Mira <- Neel

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Kid's name: Om joined the line.

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Line (front to back): Kabir <- Mira <- Neel <- Om

--- Ice Cream Truck Menu ---
1. Join line
2. Serve ice cream
3. Next kid
4. Show line
0. Exit
Choice: Goodbye!
```
