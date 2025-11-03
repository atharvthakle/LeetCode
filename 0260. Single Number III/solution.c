#include <stdlib.h>
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int xor_all = 0;

    // Step 1: XOR all numbers
    for (int i = 0; i < numsSize; i++) {
        xor_all ^= nums[i];
    }

    // Step 2: Find rightmost set bit safely
    unsigned int ux = (unsigned int)xor_all;
    unsigned int diff_bit = ux & (~ux + 1);  // equivalent to xor_all & -xor_all, but safe

    int num1 = 0, num2 = 0;

    // Step 3: Partition numbers by diff_bit
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] & diff_bit) != 0)
            num1 ^= nums[i];
        else
            num2 ^= nums[i];
    }

    // Step 4: Return result
    int *res = (int*)malloc(2 * sizeof(int));
    res[0] = num1;
    res[1] = num2;
    *returnSize = 2;

    return res;
}
