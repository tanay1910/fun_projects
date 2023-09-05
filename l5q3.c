#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure for a stack node
struct StackNode {
    char data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* newNode(char data) {
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));
    if (!node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to push a character onto the stack
void push(struct StackNode** root, char data) {
    struct StackNode* node = newNode(data);
    node->next = *root;
    *root = node;
}

// Function to pop a character from the stack
char pop(struct StackNode** root) {
    if (*root == NULL) {
        printf("Stack is empty.\n");
        exit(1);
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Function to check if a string is a palindrome using a stack
bool isPalindrome(char* str) {
    int len = strlen(str);
    struct StackNode* stack = NULL;

    // Push each character from the string onto the stack
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }

    // Compare characters from the stack with characters from the string
    for (int i = 0; i < len; i++) {
        char popped = pop(&stack);
        if (str[i] != popped) {
            return false; // Not a palindrome
        }
    }

    return true; // Palindrome
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
