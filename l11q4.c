#include <stdio.h>
#include <stdbool.h>
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

// Function to create a copy of a binary tree recursively
struct TreeNode* copyBinaryTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;

    struct TreeNode* newNode = createNode(root->data);
    newNode->left = copyBinaryTree(root->left);
    newNode->right = copyBinaryTree(root->right);

    return newNode;
}

// Function to test for equality of two binary trees recursively
bool areBinaryTreesEqual(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data) &&
           areBinaryTreesEqual(root1->left, root2->left) &&
           areBinaryTreesEqual(root1->right, root2->right);
}

// Function to free memory used by a binary tree
void freeBinaryTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    freeBinaryTree(root->left);
    freeBinaryTree(root->right);
    free(root);
}

int main() {
    // Create the original binary tree
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    // Create a copy of the binary tree
    struct TreeNode* root2 = copyBinaryTree(root1);

    // Test for equality
    bool isEqual = areBinaryTreesEqual(root1, root2);
    if (isEqual)
        printf("The two binary trees are equal.\n");
    else
        printf("The two binary trees are not equal.\n");

    // Free memory used by the binary trees
    freeBinaryTree(root1);
    freeBinaryTree(root2);

    return 0;
}
