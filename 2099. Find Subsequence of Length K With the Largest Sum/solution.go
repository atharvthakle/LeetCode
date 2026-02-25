import "sort"

func maxSubsequence(nums []int, k int) []int {
    type pair struct {
        val int
        idx int
    }

    n := len(nums)
    arr := make([]pair, n)

    // Store value with index
    for i := 0; i < n; i++ {
        arr[i] = pair{nums[i], i}
    }

    // Sort by value descending
    sort.Slice(arr, func(i, j int) bool {
        return arr[i].val > arr[j].val
    })

    // Take top k
    topK := arr[:k]

    // Sort selected elements by original index
    sort.Slice(topK, func(i, j int) bool {
        return topK[i].idx < topK[j].idx
    })

    // Build result
    result := make([]int, k)
    for i := 0; i < k; i++ {
        result[i] = topK[i].val
    }

    return result
}
