func smallestNumber(n int, t int) int {
	for {
		product := 1
		x := n

		if x == 0 {
			product = 0
		} else {
			for x > 0 {
				product *= x % 10
				x /= 10
			}
		}

		if product%t == 0 {
			return n
		}

		n++
	}
}
