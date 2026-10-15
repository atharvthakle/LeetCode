func sumCounts(nums []int) int {
    n := len(nums)
    ans := 0

    for i := 0; i < n; i++ {
        seen := make(map[int]bool)
        distinct := 0

        for j := i; j < n; j++ {
            if !seen[nums[j]] {
                seen[nums[j]] = true
                distinct++
            }
            ans += distinct * distinct
        }
    }

    return ans
}
