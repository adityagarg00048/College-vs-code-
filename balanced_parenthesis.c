#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return (top == -1) ? '\0' : stack[top--]; }

int isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return 1;
    if (char1 == '{' && char2 == '}') return 1;
    if (char1 == '[' && char2 == ']') return 1;
    return 0;
}

int areParenthesesBalanced(char exp[]) {
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (top == -1 || !isMatchingPair(pop(), exp[i])) {
                return 0;
            }
        }
    }
    return (top == -1); // True if stack is empty
}

int main() {
    char exp[] = "{()[{}]}";
    if (areParenthesesBalanced(exp))
        printf("Expression '%s' is Balanced\n", exp);
    else
        printf("Expression '%s' is Not Balanced\n", exp);
    return 0;
}