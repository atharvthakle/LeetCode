func longestMonotonicSubarray(nums []int) int {
    inc, dec, ans := 1, 1, 1

    for i := 1; i < len(nums); i++ {
        if nums[i] > nums[i-1] {
            inc++
            dec = 1
        } else if nums[i] < nums[i-1] {
            dec++
            inc = 1
        } else {
            inc = 1
            dec = 1
        }

        if inc > ans {
            ans = inc
        }
        if dec > ans {
            ans = dec
        }
    }

    return ans
}
