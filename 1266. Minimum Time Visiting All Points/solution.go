func minTimeToVisitAllPoints(points [][]int) int {
    total := 0
    
    abs := func(x int) int {
        if x < 0 {
            return -x
        }
        return x
    }
    
    for i := 1; i < len(points); i++ {
        dx := abs(points[i][0] - points[i-1][0])
        dy := abs(points[i][1] - points[i-1][1])
        if dx > dy {
            total += dx
        } else {
            total += dy
        }
    }
    
    return total
}
