func totalNumbers(digits []int) int {
	seen := make(map[int]bool)
	n := len(digits)

	for i := 0; i < n; i++ {
		if digits[i] == 0 {
			continue
		}

		for j := 0; j < n; j++ {
			if j == i {
				continue
			}

			for k := 0; k < n; k++ {
				if k == i || k == j || digits[k]%2 != 0 {
					continue
				}

				num := digits[i]*100 + digits[j]*10 + digits[k]
				seen[num] = true
			}
		}
	}

	return len(seen)
}
