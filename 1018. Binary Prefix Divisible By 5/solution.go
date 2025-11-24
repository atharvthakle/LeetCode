func prefixesDivBy5(nums []int) []bool {
    n := len(nums)
    ans := make([]bool, n)

    val := 0
    for i, bit := range nums {
        val = (val*2 + bit) % 5
        ans[i] = (val == 0)
    }

    return ans
}
