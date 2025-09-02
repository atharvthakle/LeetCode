#include <stdlib.h>
#include <string.h>

typedef struct {
    int *indices;
    int size;
    int capacity;
} Group;

long long* getDistances(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    long long *res = (long long*)calloc(arrSize, sizeof(long long));
    
    // Using a simple hash map with array of pointers for grouping indices
    int maxVal = 100000;
    Group* groups = (Group*)calloc(maxVal + 1, sizeof(Group));
    
    for (int i = 0; i <= maxVal; i++) {
        groups[i].size = 0;
        groups[i].capacity = 0;
        groups[i].indices = NULL;
    }
    
    // Group indices by value
    for (int i = 0; i < arrSize; i++) {
        int val = arr[i];
        if (groups[val].size == groups[val].capacity) {
            groups[val].capacity = groups[val].capacity == 0 ? 2 : groups[val].capacity * 2;
            groups[val].indices = (int*)realloc(groups[val].indices, groups[val].capacity * sizeof(int));
        }
        groups[val].indices[groups[val].size++] = i;
    }
    
    // Calculate intervals using prefix sums
    for (int i = 0; i <= maxVal; i++) {
        if (!groups[i].indices) continue;
        int *idx = groups[i].indices;
        int sz = groups[i].size;
        long long prefixSum = 0;
        for (int j = 0; j < sz; j++) {
            res[idx[j]] = (long long)j * idx[j] - prefixSum;
            prefixSum += idx[j];
        }
        long long suffixSum = 0;
        for (int j = sz - 1; j >= 0; j--) {
            res[idx[j]] += suffixSum - (long long)(sz - 1 - j) * idx[j];
            suffixSum += idx[j];
        }
        free(groups[i].indices);
    }
    
    free(groups);
    return res;
}
