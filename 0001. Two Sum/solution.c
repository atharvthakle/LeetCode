#include <stdio.h>
#include <stdlib.h>

// Hash map structure
typedef struct {
    int key;   // value in nums
    int index; // index of value
} HashNode;

int hash(int key, int size) {
    if (key < 0) key = -key;
    return key % size;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    // create hash table
    int hashSize = numsSize * 2;
    HashNode* hashTable = (HashNode*)calloc(hashSize, sizeof(HashNode));
    int* used = (int*)calloc(hashSize, sizeof(int)); // track filled slots

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int idx = hash(complement, hashSize);

        // search complement in hash
        while (used[idx]) {
            if (hashTable[idx].key == complement) {
                result[0] = hashTable[idx].index;
                result[1] = i;
                free(hashTable);
                free(used);
                return result;
            }
            idx = (idx + 1) % hashSize; // linear probing
        }

        // insert current number into hash
        int insertIdx = hash(nums[i], hashSize);
        while (used[insertIdx]) {
            insertIdx = (insertIdx + 1) % hashSize;
        }
        hashTable[insertIdx].key = nums[i];
        hashTable[insertIdx].index = i;
        used[insertIdx] = 1;
    }

    free(hashTable);
    free(used);
    return result;
}
