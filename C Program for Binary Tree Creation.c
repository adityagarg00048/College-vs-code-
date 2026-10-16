#include <stdio.h>
#include <stdlib.h>

// Structure representation of a Binary Tree Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Helper function to allocate memory for a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to create the tree structure from user input
Node* buildTree() {
    int data;
    printf("Enter node data (-1 for no node/NULL): ");
    scanf("%d", &data);

    // Base case: If user inputs -1, no node is created here
    if (data == -1) {
        return NULL;
    }

    // Allocate memory for the current parent node
    Node* root = createNode(data);

    // Recursively build the Left Subtree
    printf("--- Building LEFT child of node %d ---\n", data);
    root->left = buildTree();

    // Recursively build the Right Subtree
    printf("--- Building RIGHT child of node %d ---\n", data);
    root->right = buildTree();

    return root;
}

// Verification function: Pre-order Traversal (Root -> Left -> Right)
void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Verification function: In-order Traversal (Left -> Root -> Right)
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Helper function to free allocated tree memory
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    printf("Start constructing your binary tree:\n");
    Node* root = buildTree();

    printf("\n--- Tree Construction Complete ---\n");
    
    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");

    // Clean up memory
    freeTree(root);
    return 0;
}
