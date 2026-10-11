func sumOfSquares(nums []int) int {
	n := len(nums)
	sum := 0

	for i, num := range nums {
		if n%(i+1) == 0 {
			sum += num * num
		}
	}

	return sum
}
