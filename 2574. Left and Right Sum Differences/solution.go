func leftRightDifference(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)

	total := 0
	for _, num := range nums {
		total += num
	}

	leftSum := 0

	for i := 0; i < n; i++ {
		rightSum := total - leftSum - nums[i]

		diff := leftSum - rightSum
		if diff < 0 {
			diff = -diff
		}

		ans[i] = diff
		leftSum += nums[i]
	}

	return ans
}
