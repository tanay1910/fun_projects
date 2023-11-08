#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the in-order successor in a BST
struct Node* findInOrderSuccessor(struct Node* root, struct Node* target) {
    if (root == NULL || target == NULL) {
        return NULL;
    }

    struct Node* successor = NULL;
    while (root) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else {
            if (root->right) {
                root = root->right;
                while (root->left) {
                    root = root->left;
                }
                successor = root;
            }
            break;
        }
    }
    return successor;
}

int main() {
    struct Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    // Find the in-order successor for a node
    struct Node* targetNode = root->left->right; // Node with value 40
    struct Node* successor = findInOrderSuccessor(root, targetNode);

    if (successor) {
        printf("In-order successor of %d is %d\n", targetNode->data, successor->data);
    } else {
        printf("No in-order successor found for %d\n", targetNode->data);
    }

    return 0;
}
