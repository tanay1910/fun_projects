#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure to represent a stack node for iterative traversal
struct StackNode {
    struct TreeNode* data;
    struct StackNode* next;
};

// Structure to represent a queue node for level-order traversal
struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

// Push an element onto the stack
void push(struct StackNode** top, struct TreeNode* treeNode) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = treeNode;
    newNode->next = *top;
    *top = newNode;
}

// Pop an element from the stack
struct TreeNode* pop(struct StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    struct TreeNode* popped = (*top)->data;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Enqueue an element in the queue
void enqueue(struct QueueNode** front, struct QueueNode** rear, struct TreeNode* treeNode) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = treeNode;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

// Dequeue an element from the queue
struct TreeNode* dequeue(struct QueueNode** front) {
    if (*front == NULL) {
        return NULL;
    }

    struct TreeNode* dequeued = (*front)->data;
    struct QueueNode* temp = *front;
    *front = (*front)->next;

    if (*front == NULL) {
        *front = *front;
    }

    free(temp);
    return dequeued;
}

// Iterative Preorder Traversal
void iterativePreorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    push(&stack, root);

    while (stack != NULL) {
        struct TreeNode* node = pop(&stack);
        printf("%d ", node->data);

        if (node->right != NULL) {
            push(&stack, node->right);
        }

        if (node->left != NULL) {
            push(&stack, node->left);
        }
    }
}

// Iterative Inorder Traversal
void iterativeInorder(struct TreeNode* root) {
    struct TreeNode* current = root;
    struct StackNode* stack = NULL;

    while (current != NULL || stack != NULL) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

// Iterative Postorder Traversal using a single stack
void iterativePostorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    struct TreeNode* prev = NULL;

    do {
        while (root != NULL) {
            push(&stack, root);
            root = root->left;
        }

        while (root == NULL && stack != NULL) {
            struct TreeNode* peek = stack->data;

            if (peek->right == NULL || peek->right == prev) {
                printf("%d ", peek->data);
                pop(&stack);
                prev = peek;
            } else {
                root = peek->right;
            }
        }
    } while (stack != NULL);
}

// Level-Order Traversal
void levelOrder(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    enqueue(&front, &rear, root);

    while (front != NULL) {
        struct TreeNode* node = dequeue(&front);
        printf("%d ", node->data);

        if (node->left != NULL)
            enqueue(&front, &rear, node->left);
        if (node->right != NULL)
            enqueue(&front, &rear, node->right);
    }
}

// Create a new binary tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Iterative Preorder Traversal: ");
    iterativePreorder(root);
    printf("\n");

    printf("Iterative Inorder Traversal: ");
    iterativeInorder(root);
    printf("\n");

    printf("Iterative Postorder Traversal: ");
    iterativePostorder(root);
    printf("\n");

    printf("Level-Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
