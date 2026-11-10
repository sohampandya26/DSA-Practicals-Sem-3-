# Practical 7: Infix to Postfix Conversion

## Problem Statement
Convert `(A+B)*(C+D/E)-(F+G*H)` to postfix using a stack.

## Concepts Used
Stack, operator precedence & associativity, Polish notation

## Approach
Scan left to right: operands go to output; operators wait on the stack until a higher/equal precedence operator arrives; `)` pops until `(`. Prints a step-by-step table. Expected result: `AB+CDE/+*FGH*+-`.

## Complexity
| Time | Space |
|------|-------|
| O(n) | O(n) |

## How to Run
```bash
gcc -Wall -std=c11 -o infix_to_postfix infix_to_postfix.c
./infix_to_postfix < input.txt
```

## Sample Input (`input.txt`)
```
(A+B)*(C+D/E)-(F+G*H)
```

## Sample Output
```
Enter infix expression (no unicode symbols, use * for multiply):
> 
Symbol   Stack           Postfix so far
--------------------------------------------
(        (               
A        (               A
+        (+              A
B        (+              AB
)                        AB+
*        *               AB+
(        *(              AB+
C        *(              AB+C
+        *(+             AB+C
D        *(+             AB+CD
/        *(+/            AB+CD
E        *(+/            AB+CDE
)        *               AB+CDE/+
-        -               AB+CDE/+*
(        -(              AB+CDE/+*
F        -(              AB+CDE/+*F
+        -(+             AB+CDE/+*F
G        -(+             AB+CDE/+*FG
*        -(+*            AB+CDE/+*FG
H        -(+*            AB+CDE/+*FGH
)        -               AB+CDE/+*FGH*+

Infix   : (A+B)*(C+D/E)-(F+G*H)
Postfix : AB+CDE/+*FGH*+-
```
