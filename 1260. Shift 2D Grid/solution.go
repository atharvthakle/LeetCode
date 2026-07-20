func shiftGrid(grid [][]int, k int) [][]int {
	m := len(grid)
	n := len(grid[0])
	total := m * n
	k %= total

	ans := make([][]int, m)
	for i := range ans {
		ans[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			idx := i*n + j
			newIdx := (idx + k) % total
			r := newIdx / n
			c := newIdx % n
			ans[r][c] = grid[i][j]
		}
	}

	return ans
}
