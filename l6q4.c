#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_SIZE 100

// Stack implementation
struct Stack {
    char data[MAX_EXPRESSION_SIZE];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char value) {
    if (stack->top < MAX_EXPRESSION_SIZE - 1) {
        stack->data[++(stack->top)] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[(stack->top)--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}

// Function to convert prefix to postfix
void prefixToPostfix(char prefix[], char postfix[]) {
    struct Stack operatorStack;
    initializeStack(&operatorStack);

    int length = strlen(prefix);

    // Reverse the prefix expression
    for (int i = 0; i < length / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[length - 1 - i];
        prefix[length - 1 - i] = temp;
    }

    int j = 0; // Index for the output postfix expression

    for (int i = 0; i < length; i++) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch; // Operand
        } else if (isOperator(ch)) {
            while (!isEmpty(&operatorStack) &&
                   getPrecedence(ch) < getPrecedence(operatorStack.data[operatorStack.top])) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(&operatorStack)) {
        postfix[j++] = pop(&operatorStack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression

    // Reverse the obtained postfix expression to get the final result
    length = strlen(postfix);
    for (int i = 0; i < length / 2; i++) {
        char temp = postfix[i];
        postfix[i] = postfix[length - 1 - i];
        postfix[length - 1 - i] = temp;
    }
}

int main() {
    char prefix[MAX_EXPRESSION_SIZE];
    char postfix[MAX_EXPRESSION_SIZE];

    printf("Enter a prefix expression: ");
    scanf("%s",prefix);

    prefixToPostfix(prefix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
