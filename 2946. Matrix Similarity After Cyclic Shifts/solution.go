func areSimilar(mat [][]int, k int) bool {
    m := len(mat)
    n := len(mat[0])

    k = k % n

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if i%2 == 0 {
                // even row → left shift
                if mat[i][j] != mat[i][(j+k)%n] {
                    return false
                }
            } else {
                // odd row → right shift
                if mat[i][j] != mat[i][(j-k+n)%n] {
                    return false
                }
            }
        }
    }

    return true
}
