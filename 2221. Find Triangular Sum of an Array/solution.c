int triangularSum(int* nums, int numsSize) {
    // Keep reducing the array until only 1 element remains
    while (numsSize > 1) {
        for (int i = 0; i < numsSize - 1; i++) {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }
        numsSize--; // reduce size by 1
    }
    return nums[0];
}
