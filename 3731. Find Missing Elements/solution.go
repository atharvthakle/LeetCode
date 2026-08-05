func findMissingElements(nums []int) []int {
	minVal, maxVal := nums[0], nums[0]
	seen := make(map[int]bool)

	for _, num := range nums {
		seen[num] = true
		if num < minVal {
			minVal = num
		}
		if num > maxVal {
			maxVal = num
		}
	}

	var res []int
	for i := minVal; i <= maxVal; i++ {
		if !seen[i] {
			res = append(res, i)
		}
	}

	return res
}
