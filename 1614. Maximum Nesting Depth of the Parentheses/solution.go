func maxDepth(s string) int {
	depth, ans := 0, 0

	for _, c := range s {
		if c == '(' {
			depth++
			if depth > ans {
				ans = depth
			}
		} else if c == ')' {
			depth--
		}
	}

	return ans
}
