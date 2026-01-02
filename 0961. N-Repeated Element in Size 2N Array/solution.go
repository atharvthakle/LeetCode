func repeatedNTimes(nums []int) int {
    seen := make(map[int]bool)
    
    for _, v := range nums {
        if seen[v] {
            return v
        }
        seen[v] = true
    }
    return -1 // logically unreachable
}
