#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum capacity of the queue

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == -1);
}

// Add an element to the queue (Enqueue)
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Remove an element from the queue (Dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int token = q->items[q->front];
    if (q->front == q->rear) { // Only one element was present
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return token;
}

// Display the queue elements
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    return 0;
}


// Queue Using a Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure keeping track of Front and Rear pointers
typedef struct {
    Node* front;
    Node* rear;
} LinkedQueue;

// Initialize the queue
void initLinkedQueue(LinkedQueue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Add an element to the queue (Enqueue)
void enqueueLinked(LinkedQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) { // Queue is empty
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Remove an element from the queue (Dequeue)
int dequeueLinked(LinkedQueue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    Node* temp = q->front;
    int token = temp->data;
    
    q->front = q->front->next;

    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return token;
}

// Display the queue elements
void displayLinked(LinkedQueue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedQueue q;
    initLinkedQueue(&q);

    enqueueLinked(&q, 100);
    enqueueLinked(&q, 200);
    enqueueLinked(&q, 300);
    displayLinked(&q);

    printf("Dequeued: %d\n", dequeueLinked(&q));
    displayLinked(&q);

    // Memory cleanup for remaining nodes
    while (q.front != NULL) {
        dequeueLinked(&q);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure keeping track of Front and Rear pointers
typedef struct {
    Node* front;
    Node* rear;
} LinkedQueue;

// Initialize the queue
void initLinkedQueue(LinkedQueue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Add an element to the queue (Enqueue)
void enqueueLinked(LinkedQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) { // Queue is empty
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Remove an element from the queue (Dequeue)
int dequeueLinked(LinkedQueue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    Node* temp = q->front;
    int token = temp->data;
    
    q->front = q->front->next;

    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return token;
}

// Display the queue elements
void displayLinked(LinkedQueue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedQueue q;
    initLinkedQueue(&q);

    enqueueLinked(&q, 100);
    enqueueLinked(&q, 200);
    enqueueLinked(&q, 300);
    displayLinked(&q);

    printf("Dequeued: %d\n", dequeueLinked(&q));
    displayLinked(&q);

    // Memory cleanup for remaining nodes
    while (q.front != NULL) {
        dequeueLinked(&q);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure keeping track of Front and Rear pointers
typedef struct {
    Node* front;
    Node* rear;
} LinkedQueue;

// Initialize the queue
void initLinkedQueue(LinkedQueue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Add an element to the queue (Enqueue)
void enqueueLinked(LinkedQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) { // Queue is empty
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Remove an element from the queue (Dequeue)
int dequeueLinked(LinkedQueue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    Node* temp = q->front;
    int token = temp->data;
    
    q->front = q->front->next;

    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return token;
}

// Display the queue elements
void displayLinked(LinkedQueue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedQueue q;
    initLinkedQueue(&q);

    enqueueLinked(&q, 100);
    enqueueLinked(&q, 200);
    enqueueLinked(&q, 300);
    displayLinked(&q);

    printf("Dequeued: %d\n", dequeueLinked(&q));
    displayLinked(&q);

    // Memory cleanup for remaining nodes
    while (q.front != NULL) {
        dequeueLinked(&q);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure keeping track of Front and Rear pointers
typedef struct {
    Node* front;
    Node* rear;
} LinkedQueue;

// Initialize the queue
void initLinkedQueue(LinkedQueue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Add an element to the queue (Enqueue)
void enqueueLinked(LinkedQueue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) { // Queue is empty
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Remove an element from the queue (Dequeue)
int dequeueLinked(LinkedQueue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    Node* temp = q->front;
    int token = temp->data;
    
    q->front = q->front->next;

    // If front becomes NULL, then change rear also to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return token;
}

// Display the queue elements
void displayLinked(LinkedQueue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedQueue q;
    initLinkedQueue(&q);

    enqueueLinked(&q, 100);
    enqueueLinked(&q, 200);
    enqueueLinked(&q, 300);
    displayLinked(&q);

    printf("Dequeued: %d\n", dequeueLinked(&q));
    displayLinked(&q);

    // Memory cleanup for remaining nodes
    while (q.front != NULL) {
        dequeueLinked(&q);
    }

    return 0;
}
