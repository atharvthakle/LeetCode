import (
    "sort"
    "math/bits"
)

func sortByBits(arr []int) []int {
    sort.Slice(arr, func(i, j int) bool {
        countI := bits.OnesCount(uint(arr[i]))
        countJ := bits.OnesCount(uint(arr[j]))
        
        if countI == countJ {
            return arr[i] < arr[j]
        }
        return countI < countJ
    })
    
    return arr
}
