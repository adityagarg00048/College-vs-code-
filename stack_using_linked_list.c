#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", val);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
    } else {
        struct Node* temp = top;
        printf("%d popped from stack.\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    push(100);
    push(200);
    push(300);
    display();
    pop();
    display();
    return 0;
}