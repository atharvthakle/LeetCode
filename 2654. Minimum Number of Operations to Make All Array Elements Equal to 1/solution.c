#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int minOperations(int* nums, int numsSize) {
    int overallGcd = nums[0];
    for (int i = 1; i < numsSize; i++)
        overallGcd = gcd(overallGcd, nums[i]);
    
    // If the gcd of all elements is not 1, impossible
    if (overallGcd != 1)
        return -1;

    // Count how many 1s are already present
    int count1 = 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] == 1)
            count1++;

    // If we already have 1s, only need to turn others into 1s
    if (count1 > 0)
        return numsSize - count1;

    // Otherwise, find the shortest subarray whose gcd == 1
    int minLen = numsSize + 1;
    for (int i = 0; i < numsSize; i++) {
        int currGcd = nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            currGcd = gcd(currGcd, nums[j]);
            if (currGcd == 1) {
                minLen = (j - i + 1 < minLen) ? j - i + 1 : minLen;
                break;
            }
        }
    }

    // Total operations = (minLen - 1) to create first 1 + (numsSize - 1) to spread it
    return (minLen - 1) + (numsSize - 1);
}
