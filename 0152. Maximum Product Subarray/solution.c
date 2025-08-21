int maxProduct(int* nums, int numsSize) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int tempMax = maxProd;
        int tempMin = minProd;

        maxProd = fmax(nums[i], fmax(nums[i] * tempMax, nums[i] * tempMin));
        minProd = fmin(nums[i], fmin(nums[i] * tempMax, nums[i] * tempMin));

        if (maxProd > result) {
            result = maxProd;
        }
    }

    return result;
}
