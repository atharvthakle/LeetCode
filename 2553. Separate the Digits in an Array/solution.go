import "strconv"

func separateDigits(nums []int) []int {
    res := []int{}

    for _, num := range nums {
        s := strconv.Itoa(num)

        for _, ch := range s {
            res = append(res, int(ch-'0'))
        }
    }

    return res
}
