import "sort"

func minimumAbsDifference(arr []int) [][]int {
    sort.Ints(arr)
    
    n := len(arr)
    minDiff := int(2e9)
    
    // Find minimum difference
    for i := 1; i < n; i++ {
        diff := arr[i] - arr[i-1]
        if diff < minDiff {
            minDiff = diff
        }
    }
    
    // Collect pairs
    res := [][]int{}
    for i := 1; i < n; i++ {
        if arr[i]-arr[i-1] == minDiff {
            res = append(res, []int{arr[i-1], arr[i]})
        }
    }
    
    return res
}
