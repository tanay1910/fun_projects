#include <stdio.h>
#include <stdlib.h>

// Define the structure for a min-heap node
struct MinHeapNode {
    int data;
};

// Define the structure for the min-heap
struct MinHeap {
    int capacity;     // Maximum number of elements the heap can hold
    int size;         // Current number of elements in the heap
    struct MinHeapNode* array;
};

// Function to create a new min-heap node
struct MinHeapNode* createNode(int data) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    return node;
}

// Function to create a new min-heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    if (minHeap == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (struct MinHeapNode*)malloc(capacity * sizeof(struct MinHeapNode));
    if (minHeap->array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return minHeap;
}

// Function to swap two min-heap nodes
void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min-heap property after inserting a new node
void heapifyUp(struct MinHeap* minHeap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && minHeap->array[index].data < minHeap->array[parent].data) {
        swap(&minHeap->array[index], &minHeap->array[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Function to insert an element into the min-heap
void insert(struct MinHeap* minHeap, int data) {
    if (minHeap->size >= minHeap->capacity) {
        printf("Heap is full. Cannot insert %d\n", data);
        return;
    }

    int index = minHeap->size;
    minHeap->array[index] = *createNode(data);
    minHeap->size++;

    heapifyUp(minHeap, index);
}

// Function to maintain the min-heap property after extracting the minimum element
void heapifyDown(struct MinHeap* minHeap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < minHeap->size && minHeap->array[leftChild].data < minHeap->array[smallest].data) {
        smallest = leftChild;
    }

    if (rightChild < minHeap->size && minHeap->array[rightChild].data < minHeap->array[smallest].data) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&minHeap->array[index], &minHeap->array[smallest]);
        heapifyDown(minHeap, smallest);
    }
}

// Function to extract the minimum element from the min-heap
int extractMin(struct MinHeap* minHeap) {
    if (minHeap->size <= 0) {
        fprintf(stderr, "Heap is empty\n");
        exit(1);
    }

    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->array[0].data;
    }

    int root = minHeap->array[0].data;
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;

    heapifyDown(minHeap, 0);

    return root;
}

int main() {
    struct MinHeap* minHeap = createMinHeap(10);

    insert(minHeap, 3);
    insert(minHeap, 1);
    insert(minHeap, 6);
    insert(minHeap, 4);
    insert(minHeap, 2);

    printf("Extracted min: %d\n", extractMin(minHeap));
    printf("Extracted min: %d\n", extractMin(minHeap));
    printf("Extracted min: %d\n", extractMin(minHeap));

    free(minHeap->array);
    free(minHeap);

    return 0;
}
