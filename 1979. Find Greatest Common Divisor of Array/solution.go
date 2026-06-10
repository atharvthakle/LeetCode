func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func findGCD(nums []int) int {
	minVal, maxVal := nums[0], nums[0]

	for _, num := range nums {
		if num < minVal {
			minVal = num
		}
		if num > maxVal {
			maxVal = num
		}
	}

	return gcd(minVal, maxVal)
}
