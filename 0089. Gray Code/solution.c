#include <stdlib.h>

int* grayCode(int n, int* returnSize) {
    *returnSize = 1 << n;  // 2^n elements
    int* res = (int*)malloc(sizeof(int) * (*returnSize));
    
    for (int i = 0; i < *returnSize; i++) {
        // Gray code formula: G(i) = i ^ (i >> 1)
        res[i] = i ^ (i >> 1);
    }
    
    return res;
}
