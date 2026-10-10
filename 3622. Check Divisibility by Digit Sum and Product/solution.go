func checkDivisibility(n int) bool {
	sum, product := 0, 1

	for x := n; x > 0; x /= 10 {
		digit := x % 10
		sum += digit
		product *= digit
	}

	return n%(sum+product) == 0
}
