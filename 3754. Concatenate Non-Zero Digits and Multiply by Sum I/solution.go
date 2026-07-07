func sumAndMultiply(n int) int64 {
	if n == 0 {
		return 0
	}

	digits := []int{}
	temp := n

	for temp > 0 {
		d := temp % 10
		if d != 0 {
			digits = append(digits, d)
		}
		temp /= 10
	}

	var x int64
	sum := 0

	for i := len(digits) - 1; i >= 0; i-- {
		x = x*10 + int64(digits[i])
		sum += digits[i]
	}

	return x * int64(sum)
}
