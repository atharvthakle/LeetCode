func maximumLengthSubstring(s string) int {
	count := make([]int, 26)
	left := 0
	ans := 0

	for right := 0; right < len(s); right++ {
		count[s[right]-'a']++

		for count[s[right]-'a'] > 2 {
			count[s[left]-'a']--
			left++
		}

		if right-left+1 > ans {
			ans = right - left + 1
		}
	}

	return ans
}
