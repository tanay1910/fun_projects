#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Stack implementation
struct Stack {
    int data[MAX_STACK_SIZE];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->data[++(stack->top)] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[(stack->top)--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

// Function to evaluate a prefix expression
int evaluatePrefix(char expression[]) {
    struct Stack stack;
    initializeStack(&stack);

    int length = strlen(expression);

    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0'); // Convert character to integer
        } else if (expression[i] == ' ') {
            // Ignore spaces
            continue;
        } else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
            char operator = expression[i];

            switch (operator) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", operator);
                    exit(1);
            }
        }
    }

    return pop(&stack);
}

int main() {
    char expression[] = "* + 5 4 - 7 2";
    int result = evaluatePrefix(expression);
    printf("Result: %d\n", result);
    return 0;
}
