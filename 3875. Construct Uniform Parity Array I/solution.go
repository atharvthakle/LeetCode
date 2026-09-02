func uniformArray(nums1 []int) bool {
	odd, even := 0, 0

	for _, x := range nums1 {
		if x%2 == 0 {
			even++
		} else {
			odd++
		}
	}

	return odd == 0 || even == 0 || (odd > 0 && even > 0)
}
