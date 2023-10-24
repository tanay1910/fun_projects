#include <stdio.h>
#include <stdlib.h>

// Structure to represent a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new binary tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform an in-order traversal of the binary tree recursively
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform a pre-order traversal of the binary tree recursively
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform a post-order traversal of the binary tree recursively
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
