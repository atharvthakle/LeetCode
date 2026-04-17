func nextGreaterElement(nums1 []int, nums2 []int) []int {
    stack := []int{}
    next := make(map[int]int)

    // process nums2
    for _, num := range nums2 {
        for len(stack) > 0 && num > stack[len(stack)-1] {
            prev := stack[len(stack)-1]
            stack = stack[:len(stack)-1]
            next[prev] = num
        }
        stack = append(stack, num)
    }

    // remaining elements have no next greater
    for _, num := range stack {
        next[num] = -1
    }

    // build result
    res := make([]int, len(nums1))
    for i, num := range nums1 {
        res[i] = next[num]
    }

    return res
}
