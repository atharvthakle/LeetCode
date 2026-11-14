func minimumSumSubarray(nums []int, l int, r int) int {
    ans := int(^uint(0) >> 1)
    n := len(nums)

    for i := 0; i < n; i++ {
        sum := 0

        for j := i; j < n && j-i+1 <= r; j++ {
            sum += nums[j]

            if j-i+1 >= l && sum > 0 && sum < ans {
                ans = sum
            }
        }
    }

    if ans == int(^uint(0)>>1) {
        return -1
    }

    return ans
}
