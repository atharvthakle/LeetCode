func furthestDistanceFromOrigin(moves string) int {
    left, right, blank := 0, 0, 0

    for _, ch := range moves {
        if ch == 'L' {
            left++
        } else if ch == 'R' {
            right++
        } else {
            blank++
        }
    }

    diff := right - left
    if diff < 0 {
        diff = -diff
    }

    return diff + blank
}
