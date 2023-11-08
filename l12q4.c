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

// Function to construct a binary tree from pre-order and post-order traversal sequences
struct Node* constructTree(int pre[], int post[], int* preIndex, int postIndex, int size) {
    if (*preIndex >= size || postIndex >= size) {
        return NULL;
    }

    struct Node* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (root->data != post[postIndex]) {
        root->left = constructTree(pre, post, preIndex, postIndex, size);
        root->right = constructTree(pre, post, preIndex, postIndex, size);
    }

    return root;
}

// Function to print in-order traversal of a binary tree
void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);

    int preIndex = 0;
    int postIndex = 0;

    struct Node* root = constructTree(pre, post, &preIndex, postIndex, size);

    printf("In-order traversal of the constructed binary tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
