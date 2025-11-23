#include <stdlib.h>

typedef struct {
    int size;
    int* nums;
    int* bit; // Binary Indexed Tree
} NumArray;

// Helper: update BIT at index by delta
void bitUpdate(int* bit, int n, int index, int delta) {
    index++; // BIT uses 1-based indexing
    while (index <= n) {
        bit[index] += delta;
        index += index & -index;
    }
}

// Helper: prefix sum up to index in BIT
int bitQuery(int* bit, int index) {
    int sum = 0;
    index++; // 1-based
    while (index > 0) {
        sum += bit[index];
        index -= index & -index;
    }
    return sum;
}

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->size = numsSize;
    obj->nums = (int*)malloc(sizeof(int) * numsSize);
    obj->bit = (int*)calloc(numsSize + 1, sizeof(int)); // BIT 1-based, init 0

    for (int i = 0; i < numsSize; i++) {
        obj->nums[i] = nums[i];
        bitUpdate(obj->bit, numsSize, i, nums[i]);
    }
    return obj;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    int delta = val - obj->nums[index];
    obj->nums[index] = val;
    bitUpdate(obj->bit, obj->size, index, delta);
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return bitQuery(obj->bit, right) - bitQuery(obj->bit, left - 1);
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    free(obj->bit);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);
 * int param_2 = numArraySumRange(obj, left, right);
 * numArrayFree(obj);
*/
