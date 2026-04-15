func closestTarget(words []string, target string, startIndex int) int {
    n := len(words)
    res := n + 1 // large value

    for i, w := range words {
        if w == target {
            diff := i - startIndex
            if diff < 0 {
                diff = -diff
            }

            dist := diff
            if n - diff < dist {
                dist = n - diff
            }

            if dist < res {
                res = dist
            }
        }
    }

    if res == n + 1 {
        return -1
    }
    return res
}
