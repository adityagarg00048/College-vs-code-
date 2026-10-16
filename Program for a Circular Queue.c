#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Fixed capacity of the circular queue

typedef struct {
    int items[SIZE];
    int front;
    int rear;
} CircularQueue;

// Initialize queue states
void initQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is full
int isFull(CircularQueue* q) {
    if ((q->front == 0 && q->rear == SIZE - 1) || (q->rear + 1 == q->front)) {
        return 1;
    }
    return 0;
}

// Check if queue is empty
int isEmpty(CircularQueue* q) {
    return (q->front == -1);
}

// Add an element
void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Successfully inserted: %d\n", value);
}

// Remove an element
int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Nothing to remove\n");
        return -1;
    }
    
    int element = q->items[q->front];
    
    // If only one element was left, reset the queue pointers
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    
    return element;
}

// Display elements inside the queue
void display(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is currently empty!\n");
        return;
    }
    
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n[Front Index: %d, Rear Index: %d]\n", q->front, q->rear);
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---");
        printf("\n1. Enqueue (Insert)\n2. Dequeue (Delete)\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
