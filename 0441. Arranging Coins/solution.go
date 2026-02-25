func arrangeCoins(n int) int {
    left, right := 0, n
    var ans int

    for left <= right {
        mid := left + (right-left)/2
        sum := int64(mid) * int64(mid+1) / 2

        if sum <= int64(n) {
            ans = mid
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    return ans
}
