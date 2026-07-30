func minimumPushes(word string) int {
	ans := 0
	for i := 0; i < len(word); i++ {
		ans += i/8 + 1
	}
	return ans
}
