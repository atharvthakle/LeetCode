func maxDistance(colors []int) int {
    n := len(colors)
    
    res := 0

    // compare with first element
    for i := n - 1; i >= 0; i-- {
        if colors[i] != colors[0] {
            res = i
            break
        }
    }

    // compare with last element
    for i := 0; i < n; i++ {
        if colors[i] != colors[n-1] {
            if n-1-i > res {
                res = n - 1 - i
            }
            break
        }
    }

    return res
}
