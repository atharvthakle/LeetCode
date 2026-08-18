func largestInteger(nums []int, k int) int {
	count := make([]int, 51)
	n := len(nums)

	for i := 0; i <= n-k; i++ {
		seen := make([]bool, 51)

		for j := i; j < i+k; j++ {
			if !seen[nums[j]] {
				count[nums[j]]++
				seen[nums[j]] = true
			}
		}
	}

	for x := 50; x >= 0; x-- {
		if count[x] == 1 {
			return x
		}
	}

	return -1
}
