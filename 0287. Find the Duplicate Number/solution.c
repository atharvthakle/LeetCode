int findDuplicate(int* nums, int numsSize) {
    int slow = nums[0];
    int fast = nums[0];
    
    // Step 1: Detect the cycle
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    // Step 2: Find the entry point of the cycle (duplicate)
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    
    return slow;
}
