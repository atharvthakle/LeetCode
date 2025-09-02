int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize; // All elements are allowed if size <= 2

    int insertPos = 2; // Position to insert the next allowed element

    for (int i = 2; i < numsSize; i++) {
        // Compare current element with the element 2 positions before
        if (nums[i] != nums[insertPos - 2]) {
            nums[insertPos++] = nums[i];
        }
    }

    return insertPos;
}
