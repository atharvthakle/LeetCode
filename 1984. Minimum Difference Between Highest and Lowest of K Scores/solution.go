import "sort"

func minimumDifference(nums []int, k int) int {
    if k == 1 {
        return 0
    }
    
    sort.Ints(nums)
    
    n := len(nums)
    ans := int(1e9)
    
    for i := 0; i+k-1 < n; i++ {
        diff := nums[i+k-1] - nums[i]
        if diff < ans {
            ans = diff
        }
    }
    
    return ans
}
