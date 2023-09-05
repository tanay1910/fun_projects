#include <stdio.h>
#include <stdlib.h>

// Define a structure for a stack node
struct StackNode {
    int data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* newNode(int data) {
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (!node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to push an element onto the stack
void push(struct StackNode** root, int data) {
    struct StackNode* node = newNode(data);
    node->next = *root;
    *root = node;
}

// Function to pop an element from the stack
int pop(struct StackNode** root) {
    if (*root == NULL) {
        printf("Stack is empty.\n");
        exit(1);
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to convert decimal to binary using a stack
void decimalToBinary(int decimal) {
    struct StackNode* stack = NULL;

    // Handle the case when the decimal number is 0
    if (decimal == 0) {
        push(&stack, 0);
    }

    // Convert decimal to binary
    while (decimal > 0) {
        int remainder = decimal % 2;
        push(&stack, remainder);
        decimal /= 2;
    }

    // Pop and print binary digits from the stack
    printf("Binary representation: ");
    while (stack != NULL) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}
