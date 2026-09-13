#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coeff;
    int power;
    struct PolyNode* next;
};

// Create a new polynomial node
struct PolyNode* createNode(int coeff, int power) {
    struct PolyNode* newNode = (struct PolyNode*)malloc(sizeof(struct PolyNode));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Insert term at the end of the polynomial
void insertTerm(struct PolyNode** poly, int coeff, int power) {
    struct PolyNode* newNode = createNode(coeff, power);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct PolyNode* temp = *poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display the polynomial
void displayPoly(struct PolyNode* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->power);
        poly = poly->next;
        if (poly != NULL && poly->coeff >= 0) printf(" + ");
    }
    printf("\n");
}

// Add two polynomials
struct PolyNode* addPolynomials(struct PolyNode* p1, struct PolyNode* p2) {
    struct PolyNode* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->power > p2->power) {
            insertTerm(&result, p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p1->power < p2->power) {
            insertTerm(&result, p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            insertTerm(&result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Add remaining terms
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }
    return result;
}

int main() {
    struct PolyNode *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    // Polynomial 1: 5x^2 + 4x^1 + 2x^0
    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);

    // Polynomial 2: -5x^1 - 5x^0
    insertTerm(&poly2, -5, 1);
    insertTerm(&poly2, -5, 0);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    sum = addPolynomials(poly1, poly2);

    printf("Sum: ");
    displayPoly(sum);

    return 0;
}