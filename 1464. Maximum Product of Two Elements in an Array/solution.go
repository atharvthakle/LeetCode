func maxProduct(nums []int) int {
	max1, max2 := 0, 0

	for _, x := range nums {
		if x >= max1 {
			max2 = max1
			max1 = x
		} else if x > max2 {
			max2 = x
		}
	}

	return (max1 - 1) * (max2 - 1)
}
