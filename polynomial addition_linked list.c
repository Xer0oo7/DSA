#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
void insertNode(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct Node* temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print polynomial
void printPoly(struct Node* poly) {
    while (poly != NULL) {
        if (poly->pow == 0) {
            printf("%d", poly->coeff);
        }
        else if (poly->pow == 1) {
            printf("%dx", poly->coeff);
        }
        else {
            printf("%dx^%d", poly->coeff, poly->pow);
        }

        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insertNode(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            insertNode(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
        else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0)
                insertNode(&result, sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Copy remaining terms
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Function to take polynomial input from user
struct Node* inputPoly() {
    struct Node* poly = NULL;
    int n, coeff, pow;
    
    printf("Enter number of terms in polynomial: ");
    scanf("%d", &n);

    printf("Enter each term as: coefficient power\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &pow);
        insertNode(&poly, coeff, pow);
    }

    return poly;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    printf("Input Polynomial 1:\n");
    poly1 = inputPoly();

    printf("Input Polynomial 2:\n");
    poly2 = inputPoly();

    printf("\nPolynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum: ");
    printPoly(sum);

    return 0;
}
