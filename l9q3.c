#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            insertNode(&result, list1->data);
            list1 = list1->next;
        } else {
            insertNode(&result, list2->data);
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        insertNode(&result, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        insertNode(&result, list2->data);
        list2 = list2->next;
    }

    return result;
}

// Function to display the linked list
void displayList(struct Node* head, const char* className) {
    printf("%s\n", className);
    while (head != NULL) {
        printf("->%d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int N1, N2;
    scanf("%d %d", &N1, &N2);

    struct Node* classA = NULL;
    struct Node* classB = NULL;

    // Read heights for class A
    for (int i = 0; i < N1; i++) {
        int height;
        scanf("%d", &height);
        insertNode(&classA, height);
    }

    // Read heights for class B
    for (int i = 0; i < N2; i++) {
        int height;
        scanf("%d", &height);
        insertNode(&classB, height);
    }

    displayList(classA, "Class A");
    displayList(classB, "Class B");

    struct Node* jointClass = mergeLists(classA, classB);
    displayList(jointClass, "Joint Class");

    return 0;
}
