func numOfSubarrays(arr []int) int {
    const mod = 1_000_000_007

    even, odd := 1, 0
    prefix := 0
    ans := 0

    for _, num := range arr {
        prefix = (prefix + num) % 2

        if prefix == 0 {
            ans = (ans + odd) % mod
            even++
        } else {
            ans = (ans + even) % mod
            odd++
        }
    }

    return ans
}
