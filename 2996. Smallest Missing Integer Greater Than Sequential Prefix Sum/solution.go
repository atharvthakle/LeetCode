func missingInteger(nums []int) int {
	sum := nums[0]

	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1]+1 {
			sum += nums[i]
		} else {
			break
		}
	}

	seen := make(map[int]bool)
	for _, x := range nums {
		seen[x] = true
	}

	for !seen[sum] {
		return sum
	}

	for seen[sum] {
		sum++
	}

	return sum
}
