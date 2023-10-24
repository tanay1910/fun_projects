#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Define a structure for expression tree nodes
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Define a stack for the expression tree nodes
struct Stack {
    struct Node** items;
    int top;
    int capacity;
};

// Create a new node with the given data
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Create a new stack with the given capacity
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (struct Node**)malloc(sizeof(struct Node*) * capacity);
    return stack;
}

// Push a node onto the stack
void push(struct Stack* stack, struct Node* item) {
    stack->items[++stack->top] = item;
}

// Pop a node from the stack
struct Node* pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

// Check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Build the expression tree from the postfix expression
struct Node* buildExpressionTree(char postfix[]) {
    struct Stack* stack = createStack(strlen(postfix));

    for (int i = 0; postfix[i]; i++) {
        struct Node* newNode = createNode(postfix[i]);
        if (isOperator(postfix[i])) {
            newNode->right = pop(stack);
            newNode->left = pop(stack);
        }
        push(stack, newNode);
    }

    return pop(stack);
}

// Evaluate the expression tree
int evaluateExpressionTree(struct Node* root) {
    if (!root)
        return 0;

    if (!isOperator(root->data))
        return root->data - '0';

    int left = evaluateExpressionTree(root->left);
    int right = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
    }
    return 0;
}

int main() {
    char postfix[] = "34+5*";
    struct Node* root = buildExpressionTree(postfix);
    printf("Postfix expression: %s\n", postfix);
    printf("Result: %d\n", evaluateExpressionTree(root));
    return 0;
}
