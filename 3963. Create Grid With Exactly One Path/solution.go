func createGrid(m int, n int) []string {
    grid := make([][]byte, m)

    for i := 0; i < m; i++ {
        grid[i] = make([]byte, n)
        for j := 0; j < n; j++ {
            grid[i][j] = '#'
        }
    }

    for i := 0; i < m; i++ {
        grid[i][n-1] = '.'
    }

    for j := 0; j < n; j++ {
        grid[0][j] = '.'
    }

    for i := 1; i < m; i++ {
        grid[i][n-1] = '.'
    }

    if m > 1 && n > 1 {
        for i := 1; i < m; i++ {
            grid[i][n-1] = '.'
        }
    }

    result := make([]string, m)
    for i := 0; i < m; i++ {
        result[i] = string(grid[i])
    }

    return result
}
