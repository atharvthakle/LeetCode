func findRotation(mat [][]int, target [][]int) bool {
    n := len(mat)

    // helper to check equality
    isEqual := func(a, b [][]int) bool {
        for i := 0; i < n; i++ {
            for j := 0; j < n; j++ {
                if a[i][j] != b[i][j] {
                    return false
                }
            }
        }
        return true
    }

    // rotate matrix 90° clockwise in-place
    rotate := func(m [][]int) {
        // transpose
        for i := 0; i < n; i++ {
            for j := i + 1; j < n; j++ {
                m[i][j], m[j][i] = m[j][i], m[i][j]
            }
        }
        // reverse each row
        for i := 0; i < n; i++ {
            for j := 0; j < n/2; j++ {
                m[i][j], m[i][n-1-j] = m[i][n-1-j], m[i][j]
            }
        }
    }

    for k := 0; k < 4; k++ {
        if isEqual(mat, target) {
            return true
        }
        rotate(mat)
    }

    return false
}
