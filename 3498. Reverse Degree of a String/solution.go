func reverseDegree(s string) int {
	ans := 0

	for i := 0; i < len(s); i++ {
		reversePos := int('z'-s[i]) + 1
		ans += reversePos * (i + 1)
	}

	return ans
}
