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

// Function to print all the ancestors of a key in the binary tree
int printAncestors(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    // If the current node is the key, no need to print ancestors
    if (root->data == key) {
        return 1;
    }

    // If key is present in either the left or right subtree, print the current node
    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int key = 5;

    printf("Ancestors of %d: ", key);
    printAncestors(root, key);
    
    return 0;
}
