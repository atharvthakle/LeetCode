int singleNumber(int* nums, int numsSize) {
    int result = 0;

    for (int i = 0; i < 32; i++) {
        int sum = 0;

        for (int j = 0; j < numsSize; j++) {
            if ((nums[j] >> i) & 1) {
                sum++;
            }
        }

        if (sum % 3 != 0) {
            result |= (1U << i);  // use unsigned to avoid overflow
        }
    }

    return result;
}
