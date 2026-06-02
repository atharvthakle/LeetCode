func isGood(nums []int) bool {
	n := 0

	for _, x := range nums {
		if x > n {
			n = x
		}
	}

	// base[n] has length n + 1
	if len(nums) != n+1 {
		return false
	}

	freq := make([]int, n+1)

	for _, x := range nums {
		if x < 1 || x > n {
			return false
		}
		freq[x]++
	}

	for i := 1; i < n; i++ {
		if freq[i] != 1 {
			return false
		}
	}

	return freq[n] == 2
}
