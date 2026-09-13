#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }

int evaluatePostfix(char* exp) {
    char* e = exp;
    while (*e != '\0') {
        if (isdigit(*e)) {
            push(*e - '0'); // Convert char to int
        } else {
            int val1 = pop();
            int val2 = pop();
            switch (*e) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
        e++;
    }
    return pop();
}

int main() {
    char exp[] = "53+82-*"; // Equivalent to (5+3) * (8-2) = 8 * 6 = 48
    printf("Postfix Expression: %s\n", exp);
    printf("Evaluation Result: %d\n", evaluatePostfix(exp));
    return 0;
}