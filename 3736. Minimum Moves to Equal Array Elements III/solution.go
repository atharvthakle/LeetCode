func minMoves(nums []int) int {
    minVal := nums[0]
    sum := 0

    for _, num := range nums {
        if num < minVal {
            minVal = num
        }
        sum += num
    }

    return sum - len(nums)*minVal
}
