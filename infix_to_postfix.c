#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) { stack[++top] = x; }
char pop() { return (top == -1) ? -1 : stack[top--]; }
char peek() { return (top == -1) ? -1 : stack[top]; }

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

void infixToPostfix(char* exp) {
    char* e = exp;
    char x;
    printf("Postfix: ");
    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } else {
            while (top != -1 && precedence(peek()) >= precedence(*e)) {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1) printf("%c", pop());
    printf("\n");
}

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    // Modified for standard operators:
    char exp2[] = "A+B*C-D/E"; 
    printf("Infix: %s\n", exp2);
    infixToPostfix(exp2);
    return 0;
}