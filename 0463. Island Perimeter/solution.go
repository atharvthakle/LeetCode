func islandPerimeter(grid [][]int) int {
    rows := len(grid)
    cols := len(grid[0])
    perimeter := 0

    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            if grid[i][j] == 1 {
                perimeter += 4

                if i > 0 && grid[i-1][j] == 1 {
                    perimeter -= 2
                }

                if j > 0 && grid[i][j-1] == 1 {
                    perimeter -= 2
                }
            }
        }
    }

    return perimeter
}
