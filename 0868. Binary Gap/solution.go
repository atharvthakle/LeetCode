func binaryGap(n int) int {
    last := -1
    maxDist := 0
    pos := 0

    for n > 0 {
        if (n & 1) == 1 {
            if last != -1 {
                dist := pos - last
                if dist > maxDist {
                    maxDist = dist
                }
            }
            last = pos
        }
        n >>= 1
        pos++
    }

    return maxDist
}
