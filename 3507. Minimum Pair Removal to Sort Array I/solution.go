func minimumPairRemoval(nums []int) int {
    ops := 0
    
    // Helper: check if array is non-decreasing
    isSorted := func(arr []int) bool {
        for i := 1; i < len(arr); i++ {
            if arr[i] < arr[i-1] {
                return false
            }
        }
        return true
    }
    
    for !isSorted(nums) {
        // Find leftmost adjacent pair with minimum sum
        minSum := nums[0] + nums[1]
        idx := 0
        for i := 1; i < len(nums)-1; i++ {
            s := nums[i] + nums[i+1]
            if s < minSum {
                minSum = s
                idx = i
            }
        }
        
        // Merge pair at idx and idx+1
        merged := minSum
        newArr := make([]int, 0, len(nums)-1)
        
        newArr = append(newArr, nums[:idx]...)
        newArr = append(newArr, merged)
        newArr = append(newArr, nums[idx+2:]...)
        
        nums = newArr
        ops++
    }
    
    return ops
}
