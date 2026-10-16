#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    int priority;       // Lower value indicates higher priority
    struct Node* next;
} Node;

// Structure to wrap the head pointer
typedef struct {
    Node* front;
} PriorityQueue;

// Initialize the priority queue
void initQueue(PriorityQueue* q) {
    q->front = NULL;
}

// Check if the queue is empty
int isEmpty(PriorityQueue* q) {
    return (q->front == NULL);
}

// Add an element based on its priority (Sorted Insertion)
void enqueue(PriorityQueue* q, int value, int priority) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    // Case 1: Queue is empty OR new node has higher priority than the head node
    if (q->front == NULL || priority < q->front->priority) {
        newNode->next = q->front;
        q->front = newNode;
    } 
    // Case 2: Traverse the list to find the correct position
    else {
        Node* temp = q->front;
        // Move until the end of the list OR until we find a node with lower priority
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Enqueued: [Data: %d, Priority: %d]\n", value, priority);
}

// Remove the highest priority element (Always from the front)
int dequeue(PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Nothing to dequeue.\n");
        return -1;
    }

    Node* temp = q->front;
    int data = temp->data;
    
    q->front = q->front->next;
    free(temp);
    
    return data;
}

// Peak at the highest priority element without removing it
int peek(PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

// Display the entire queue layout
void display(PriorityQueue* q) {
    if (isEmpty(q)) {
        printf("Priority Queue is empty!\n");
        return;
    }

    Node* temp = q->front;
    printf("Priority Queue Layout (Sorted):\n");
    while (temp != NULL) {
        printf("[Data: %d | Prio: %d] -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    PriorityQueue q;
    initQueue(&q);

    // Enqueue elements in random order of priority
    enqueue(&q, 30, 3);
    enqueue(&q, 10, 1); // Highest priority
    enqueue(&q, 40, 4);
    enqueue(&q, 20, 2);
    enqueue(&q, 15, 2); // Same priority as 20, should sit behind it
    
    printf("\n");
    display(&q);
    printf("\n");

    printf("Highest Priority Element (Peek): %d\n", peek(&q));
    
    printf("Dequeued item: %d\n", dequeue(&q));
    printf("Dequeued item: %d\n", dequeue(&q));
    
    printf("\n");
    display(&q);

    // Clean up remaining memory
    while (!isEmpty(&q)) {
        dequeue(&q);
    }

    return 0;
}
