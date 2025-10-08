int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If mid element is greater than the rightmost one,
        // the minimum lies in the right half
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } 
        // Else, it lies in the left half (including mid)
        else {
            right = mid;
        }
    }

    // At the end, left == right, pointing to the minimum
    return nums[left];
}
