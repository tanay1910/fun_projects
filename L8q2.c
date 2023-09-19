#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct DequeNode {
    char data[100]; // Assume a maximum string length of 100 characters
};

struct Deque {
    struct DequeNode* arr[MAX_SIZE];
    int front;
    int rear;
};

// Function to create a new node
struct DequeNode* createNode(const char* str) {
    struct DequeNode* newNode = (struct DequeNode*)malloc(sizeof(struct DequeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->data, str);
    return newNode;
}

// Function to create a new deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    if (deque == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == -1);
}

// Function to check if the deque is full
int isFull(struct Deque* deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, const char* str) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert %s at the front.\n", str);
        return;
    }

    struct DequeNode* newNode = createNode(str);

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    deque->arr[deque->front] = newNode;
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, const char* str) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot insert %s at the rear.\n", str);
        return;
    }

    struct DequeNode* newNode = createNode(str);

    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }

    deque->arr[deque->rear] = newNode;
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return;
    }

    struct DequeNode* deletedNode = deque->arr[deque->front];
    printf("Deleted from the front: %s\n", deletedNode->data);
    free(deletedNode);

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
}

// Function to display the elements in the deque
void display(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    int current = deque->front;
    printf("Deque elements: ");
    while (current != deque->rear) {
        printf("%s ", deque->arr[current]->data);
        current = (current + 1) % MAX_SIZE;
    }
    printf("%s\n", deque->arr[current]->data);
}

int main() {
    struct Deque* deque = createDeque();

    insertRear(deque, "Apple");
    insertFront(deque, "Banana");
    insertRear(deque, "Cherry");
    insertFront(deque, "Date");

    display(deque);

    deleteFront(deque);
    display(deque);

    insertFront(deque, "Fig");
    display(deque);

    insertRear(deque, "Grapes"); // Deque is full at this point
    deleteFront(deque);

    free(deque);

    return 0;
}
