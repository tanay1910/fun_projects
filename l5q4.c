#include <stdio.h>
#include <stdlib.h>

// Function to delete k elements smaller than the next element
void deleteKElements(int arr[], int n, int k) {
    if (k >= n - 1) {
        // If k is greater than or equal to n-1, we can delete all elements except the maximum one.
        int max_element = arr[n - 1];
        printf("%d ", max_element);
        return;
    }

    int* stack = (int*)malloc(sizeof(int) * n);
    int top = -1; // Initialize stack top

    int i = 0;
    while (i < n) {
        // If stack is not empty and k is greater than 0,
        // and the current element is smaller than the top element of the stack
        while (top != -1 && k > 0 && arr[i] < stack[top]) {
            top--;
            k--;
        }

        // Push the current element onto the stack
        stack[++top] = arr[i];
        i++;
    }

    // Print the remaining elements in the stack (they are larger than the next element)
    while (k > 0) {
        top--;
        k--;
    }

    for (int j = 0; j <= top; j++) {
        printf("%d ", stack[j]);
    }

    free(stack);
}

int main() {
    int arr[] = {20, 10, 25, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    printf("Output: ");
    deleteKElements(arr, n, k);

    return 0;
}
