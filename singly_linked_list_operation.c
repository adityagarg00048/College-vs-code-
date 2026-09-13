#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// 1. Insertion (At the end)
void insertEnd(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* last = *head;
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

// 2. Deletion (By value)
void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; // Key not found
    prev->next = temp->next;
    free(temp);
}

// 3. Traversal / Display
void display(struct Node* node) {
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// 4. Search
int search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) return 1; // Found
        current = current->next;
    }
    return 0; // Not found
}

// 5. Count Nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// 6. Reverse
void reverse(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    
    display(head);
    printf("Total Nodes: %d\n", countNodes(head));
    
    printf("Searching for 20: %s\n", search(head, 20) ? "Found" : "Not Found");
    
    deleteNode(&head, 20);
    printf("After deleting 20:\n");
    display(head);
    
    reverse(&head);
    printf("After Reversing:\n");
    display(head);

    return 0;
}