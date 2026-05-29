func minElement(nums []int) int {
    ans := int(1e9)

    for _, num := range nums {
        sum := 0

        for num > 0 {
            sum += num % 10
            num /= 10
        }

        if sum < ans {
            ans = sum
        }
    }

    return ans
}
