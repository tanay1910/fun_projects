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

// Function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    struct Stack operatorStack;
    initializeStack(&operatorStack);

    int length = strlen(infix);

    // Reverse the infix expression
    for (int i = 0; i < length / 2; i++) {
        char temp = infix[i];
        infix[i] = infix[length - 1 - i];
        infix[length - 1 - i] = temp;
    }

    int j = 0; // Index for the output prefix expression

    for (int i = 0; i < length; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            prefix[j++] = ch; // Operand
        } else if (ch == ')') {
            push(&operatorStack, ch);
        } else if (ch == '(') {
            while (!isEmpty(&operatorStack) && operatorStack.data[operatorStack.top] != ')') {
                prefix[j++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Pop the corresponding '('
        } else if (isOperator(ch)) {
            while (!isEmpty(&operatorStack) && getPrecedence(ch) <= getPrecedence(operatorStack.data[operatorStack.top])) {
                prefix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(&operatorStack)) {
        prefix[j++] = pop(&operatorStack);
    }

    prefix[j] = '\0'; // Null-terminate the prefix expression

    // Reverse the obtained prefix expression to get the final result
    length = strlen(prefix);
    for (int i = 0; i < length / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[length - 1 - i];
        prefix[length - 1 - i] = temp;
    }
}

int main() {
    char infix[MAX_EXPRESSION_SIZE];
    char prefix[MAX_EXPRESSION_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s",infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
