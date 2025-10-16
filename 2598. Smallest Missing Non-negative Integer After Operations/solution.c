#include <stdlib.h>

int findSmallestInteger(int* nums, int numsSize, int value) {
    // To handle negative numbers, we normalize modulo values to [0, value-1]
    int* freq = (int*)calloc(value, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int mod = ((nums[i] % value) + value) % value; // normalize
        freq[mod]++;
    }

    int mex = 0;
    while (1) {
        int mod = mex % value;
        if (freq[mod] == 0) break; // missing remainder found
        freq[mod]--;
        mex++;
    }

    free(freq);
    return mex;
}
