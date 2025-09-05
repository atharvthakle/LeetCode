#include <stdio.h>
#include <stdlib.h>

// Swap helper
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Heapify down (min-heap)
void heapify(int *heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Build heap
void buildHeap(int *heap, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }
}

// Replace root and fix heap
void heapReplace(int *heap, int size, int val) {
    if (val > heap[0]) {
        heap[0] = val;
        heapify(heap, size, 0);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    // Step 1: make a heap of first k elements
    int *heap = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        heap[i] = nums[i];
    }
    buildHeap(heap, k);

    // Step 2: process remaining elements
    for (int i = k; i < numsSize; i++) {
        heapReplace(heap, k, nums[i]);
    }

    int result = heap[0];
    free(heap);
    return result;
}
