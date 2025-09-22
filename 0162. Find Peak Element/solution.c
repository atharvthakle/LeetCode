int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // Peak lies on the right
            left = mid + 1;
        } else {
            // Peak lies on the left (including mid)
            right = mid;
        }
    }

    // left == right → peak index
    return left;
}
