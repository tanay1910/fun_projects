#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

typedef struct CircularLinkedList {
    Node* header;
} CircularLinkedList;

CircularLinkedList* createList() {
    CircularLinkedList* list = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    list->header = (Node*)malloc(sizeof(Node));
    list->header->next = list->header;
    return list;
}

void insertTerm(CircularLinkedList* list, int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = list->header->next;
    list->header->next = newNode;
}

void displayPolynomial(CircularLinkedList* list) {
    Node* current = list->header->next;
    while (current != list->header) {
        printf("%dX^%d ", current->coefficient, current->exponent);
        current = current->next;
        if (current != list->header) {
            printf("+ ");
        }
    }
    printf("\n");
}

void subtractPolynomials(CircularLinkedList* result, CircularLinkedList* poly1, CircularLinkedList* poly2) {
    Node* term1 = poly1->header->next;
    Node* term2 = poly2->header->next;

    while (term1 != poly1->header && term2 != poly2->header) {
        if (term1->exponent == term2->exponent) {
            insertTerm(result, term1->coefficient - term2->coefficient, term1->exponent);
            term1 = term1->next;
            term2 = term2->next;
        } else if (term1->exponent > term2->exponent) {
            insertTerm(result, term1->coefficient, term1->exponent);
            term1 = term1->next;
        } else {
            insertTerm(result, -term2->coefficient, term2->exponent);
            term2 = term2->next;
        }
    }

    while (term1 != poly1->header) {
        insertTerm(result, term1->coefficient, term1->exponent);
        term1 = term1->next;
    }

    while (term2 != poly2->header) {
        insertTerm(result, -term2->coefficient, term2->exponent);
        term2 = term2->next;
    }
}

void multiplyPolynomials(CircularLinkedList* result, CircularLinkedList* poly1, CircularLinkedList* poly2) {
    Node* term1 = poly1->header->next;

    while (term1 != poly1->header) {
        Node* term2 = poly2->header->next;

        while (term2 != poly2->header) {
            insertTerm(result, term1->coefficient * term2->coefficient, term1->exponent + term2->exponent);
            term2 = term2->next;
        }

        term1 = term1->next;
    }
}

int main() {
    CircularLinkedList* poly1 = createList();
    CircularLinkedList* poly2 = createList();
    CircularLinkedList* result = createList();
    int choice;

    while (1) {
        printf("Polynomial Operations Menu:\n");
        printf("1. Enter Polynomial 1\n");
        printf("2. Enter Polynomial 2\n");
        printf("3. Subtract Polynomials\n");
        printf("4. Multiply Polynomials\n");
        printf("5. Display Result\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Polynomial 1: (Enter coefficient and exponent, 0 0 to stop)\n");
                while (1) {
                    int coeff, exp;
                    scanf("%d %d", &coeff, &exp);
                    if (coeff == 0 && exp == 0) {
                        break;
                    }
                    insertTerm(poly1, coeff, exp);
                }
                break;
            case 2:
                printf("Enter Polynomial 2: (Enter coefficient and exponent, 0 0 to stop)\n");
                while (1) {
                    int coeff, exp;
                    scanf("%d %d", &coeff, &exp);
                    if (coeff == 0 && exp == 0) {
                        break;
                    }
                    insertTerm(poly2, coeff, exp);
                }
                break;
            case 3:
                subtractPolynomials(result, poly1, poly2);
                printf("Polynomials subtracted.\n");
                break;
            case 4:
                multiplyPolynomials(result, poly1, poly2);
                printf("Polynomials multiplied.\n");
                break;
            case 5:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                printf("Result: ");
                displayPolynomial(result);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
