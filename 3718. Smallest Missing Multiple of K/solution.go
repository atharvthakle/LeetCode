func missingMultiple(nums []int, k int) int {
	seen := make(map[int]bool)

	for _, num := range nums {
		seen[num] = true
	}

	for multiple := k; ; multiple += k {
		if !seen[multiple] {
			return multiple
		}
	}
}
