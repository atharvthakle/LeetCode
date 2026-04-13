func getMinDistance(nums []int, target int, start int) int {
    res := len(nums) // large initial value

    for i, v := range nums {
        if v == target {
            diff := i - start
            if diff < 0 {
                diff = -diff
            }
            if diff < res {
                res = diff
            }
        }
    }

    return res
}
