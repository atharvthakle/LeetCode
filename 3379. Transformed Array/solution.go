func constructTransformedArray(nums []int) []int {
    n := len(nums)
    result := make([]int, n)

    for i := 0; i < n; i++ {
        if nums[i] == 0 {
            result[i] = 0
            continue
        }

        newIndex := (i + nums[i]) % n
        if newIndex < 0 {
            newIndex += n
        }

        result[i] = nums[newIndex]
    }

    return result
}
