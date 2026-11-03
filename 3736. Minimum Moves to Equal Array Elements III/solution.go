func minMoves(nums []int) int {
    maxVal := nums[0]
    sum := 0

    for _, num := range nums {
        if num > maxVal {
            maxVal = num
        }
        sum += num
    }

    return len(nums)*maxVal - sum
}
