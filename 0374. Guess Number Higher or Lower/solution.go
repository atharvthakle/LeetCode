func guessNumber(n int) int {
    left, right := 1, n

    for left <= right {
        mid := left + (right-left)/2
        res := guess(mid)

        if res == 0 {
            return mid
        } else if res < 0 {
            // mid is higher than the picked number
            right = mid - 1
        } else {
            // mid is lower than the picked number
            left = mid + 1
        }
    }

    return -1 // unreachable (guaranteed solution exists)
}
