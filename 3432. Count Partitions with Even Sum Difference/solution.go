func countPartitions(nums []int) int {
    total := 0
    for _, v := range nums {
        total += v
    }

    if total%2 == 0 {
        return len(nums) - 1
    }
    return 0
}
