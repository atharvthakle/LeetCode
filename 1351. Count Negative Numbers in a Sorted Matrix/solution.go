func countNegatives(grid [][]int) int {
    m, n := len(grid), len(grid[0])
    row, col := m-1, 0
    count := 0

    for row >= 0 && col < n {
        if grid[row][col] < 0 {
            count += n - col
            row--
        } else {
            col++
        }
    }
    return count
}
