#include <stdio.h>
#include <stdlib.h>

// Hash map structure
typedef struct {
    int key;
    int count;
} Pair;

// Comparator for qsort (used in bucket filling)
int cmp(const void* a, const void* b) {
    return ((Pair*)b)->count - ((Pair*)a)->count;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // Create a large hash map (simple linear probing)
    int mapSize = numsSize * 2 + 1;
    Pair* map = (Pair*)calloc(mapSize, sizeof(Pair));
    int* used = (int*)calloc(mapSize, sizeof(int));  // 0 = empty, 1 = used

    // Insert or update frequency in hash map
    for (int i = 0; i < numsSize; i++) {
        int key = nums[i];
        int hash = (key + 10000) % mapSize;  // offset negatives
        while (used[hash] && map[hash].key != key)
            hash = (hash + 1) % mapSize;
        if (!used[hash]) {
            used[hash] = 1;
            map[hash].key = key;
            map[hash].count = 1;
        } else {
            map[hash].count++;
        }
    }

    // Move valid pairs into an array
    Pair* freqArr = (Pair*)malloc(numsSize * sizeof(Pair));
    int freqSize = 0;
    for (int i = 0; i < mapSize; i++) {
        if (used[i]) {
            freqArr[freqSize++] = map[i];
        }
    }

    // Sort by frequency descending
    qsort(freqArr, freqSize, sizeof(Pair), cmp);

    // Prepare result array
    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        res[i] = freqArr[i].key;
    }

    *returnSize = k;

    // Free temp memory
    free(map);
    free(used);
    free(freqArr);

    return res;
}
