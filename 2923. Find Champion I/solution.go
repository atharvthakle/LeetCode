func findChampion(grid [][]int) int {
    n := len(grid)

    for i := 0; i < n; i++ {
        isChampion := true
        for j := 0; j < n; j++ {
            if i != j && grid[j][i] == 1 {
                isChampion = false
                break
            }
        }
        if isChampion {
            return i
        }
    }

    return -1 // logically unreachable due to problem guarantees
}
