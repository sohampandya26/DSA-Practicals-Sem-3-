/*
 * Practical 7 : Convert an infix expression to postfix using a Stack
 * Sample      : (A+B)*(C+D/E)-(F+G*H)   ->   AB+CDE/+*FGH*+-
 * Supports    : operands (letters/digits), + - * / % ^ and parentheses
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 256

static char stack[MAX];
static int  top = -1;

static void push(char c) { stack[++top] = c; }
static char pop(void)    { return stack[top--]; }
static char peek(void)   { return stack[top]; }

static int precedence(char op)
{
    switch (op) {
    case '^': return 3;
    case '*': case '/': case '%': return 2;
    case '+': case '-': return 1;
    default:  return 0;
    }
}

static int isOperator(char c) { return strchr("+-*/%^", c) != NULL; }

static void printStack(void)
{
    for (int i = 0; i <= top; i++) putchar(stack[i]);
}

/* returns 0 on success, -1 on error */
int infixToPostfix(const char *infix, char *postfix)
{
    int k = 0;
    top = -1;

    printf("\n%-8s %-15s %s\n", "Symbol", "Stack", "Postfix so far");
    printf("--------------------------------------------\n");

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isspace((unsigned char)c)) continue;

        if (isalnum((unsigned char)c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') postfix[k++] = pop();
            if (top == -1) { printf("Error: unbalanced ')'\n"); return -1; }
            pop();                                   /* discard '(' */
        } else if (isOperator(c)) {
            while (top != -1 && peek() != '(' &&
                   (precedence(peek()) > precedence(c) ||
                    (precedence(peek()) == precedence(c) && c != '^')))   /* ^ is right-associative */
                postfix[k++] = pop();
            push(c);
        } else {
            printf("Error: invalid character '%c'\n", c);
            return -1;
        }
        postfix[k] = '\0';
        printf("%-8c ", c);
        printStack();
        for (int pad = top + 1; pad < 15; pad++) putchar(' ');   /* align columns */
        printf(" %s\n", postfix);
    }

    while (top != -1) {
        if (peek() == '(') { printf("Error: unbalanced '('\n"); return -1; }
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    return 0;
}

int main(void)
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (no unicode symbols, use * for multiply):\n> ");
    if (!fgets(infix, sizeof infix, stdin)) return 1;
    infix[strcspn(infix, "\n")] = '\0';

    if (infixToPostfix(infix, postfix) == 0) {
        printf("\nInfix   : %s\nPostfix : %s\n", infix, postfix);
        return 0;
    }
    return 1;
}
