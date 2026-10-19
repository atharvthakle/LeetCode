func targetIndices(nums []int, target int) []int {
    less, equal := 0, 0

    for _, num := range nums {
        if num < target {
            less++
        } else if num == target {
            equal++
        }
    }

    result := make([]int, equal)
    for i := 0; i < equal; i++ {
        result[i] = less + i
    }

    return result
}
