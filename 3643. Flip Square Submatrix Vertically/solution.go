func reverseSubmatrix(grid [][]int, x int, y int, k int) [][]int {
    for i := 0; i < k/2; i++ {
        top := x + i
        bottom := x + (k - 1 - i)

        for j := 0; j < k; j++ {
            col := y + j
            grid[top][col], grid[bottom][col] = grid[bottom][col], grid[top][col]
        }
    }
    return grid
}
