#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct TwoStacks {
    int data[MAX_SIZE];
    int top1;  // Top index for the first stack
    int top2;  // Top index for the second stack
};

// Initialize the two stacks
void initialize(struct TwoStacks* twoStacks) {
    twoStacks->top1 = -1;
    twoStacks->top2 = MAX_SIZE;
}

// Push an element onto the first stack
void push1(struct TwoStacks* twoStacks, int value) {
    if (twoStacks->top1 < twoStacks->top2 - 1) {
        twoStacks->data[++(twoStacks->top1)] = value;
    } else {
        printf("Stack 1 overflow\n");
        exit(1);
    }
}

// Push an element onto the second stack
void push2(struct TwoStacks* twoStacks, int value) {
    if (twoStacks->top1 < twoStacks->top2 - 1) {
        twoStacks->data[--(twoStacks->top2)] = value;
    } else {
        printf("Stack 2 overflow\n");
        exit(1);
    }
}

// Pop an element from the first stack
int pop1(struct TwoStacks* twoStacks) {
    if (twoStacks->top1 >= 0) {
        return twoStacks->data[(twoStacks->top1)--];
    } else {
        printf("Stack 1 underflow\n");
        exit(1);
    }
}

// Pop an element from the second stack
int pop2(struct TwoStacks* twoStacks) {
    if (twoStacks->top2 < MAX_SIZE) {
        return twoStacks->data[(twoStacks->top2)++];
    } else {
        printf("Stack 2 underflow\n");
        exit(1);
    }
}

int main() {
    struct TwoStacks twoStacks;
    initialize(&twoStacks);

    push1(&twoStacks, 1);
    push1(&twoStacks, 2);
    push1(&twoStacks, 3);

    push2(&twoStacks, 4);
    push2(&twoStacks, 5);
    push2(&twoStacks, 6);

    printf("Popped from stack 1: %d\n", pop1(&twoStacks)); // 3
    printf("Popped from stack 2: %d\n", pop2(&twoStacks)); // 6

    return 0;
}
