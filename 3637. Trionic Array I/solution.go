func isTrionic(nums []int) bool {
	n := len(nums)
	if n < 4 {
		return false
	}

	i := 1

	// 1️⃣ strictly increasing
	for i < n && nums[i] > nums[i-1] {
		i++
	}
	if i == 1 || i == n {
		return false
	}

	// 2️⃣ strictly decreasing
	for i < n && nums[i] < nums[i-1] {
		i++
	}
	if i == n {
		return false
	}

	// 3️⃣ strictly increasing again
	for i < n && nums[i] > nums[i-1] {
		i++
	}

	return i == n
}
