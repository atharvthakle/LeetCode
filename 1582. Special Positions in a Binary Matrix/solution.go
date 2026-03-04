func numSpecial(mat [][]int) int {
    m := len(mat)
    n := len(mat[0])
    
    row := make([]int, m)
    col := make([]int, n)
    
    // Count ones in rows and columns
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if mat[i][j] == 1 {
                row[i]++
                col[j]++
            }
        }
    }
    
    count := 0
    
    // Check special positions
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if mat[i][j] == 1 && row[i] == 1 && col[j] == 1 {
                count++
            }
        }
    }
    
    return count
}
