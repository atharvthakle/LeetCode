func maxNumberOfBalloons(text string) int {
	cnt := make([]int, 26)

	for _, ch := range text {
		cnt[ch-'a']++
	}

	ans := cnt['b'-'a']
	if cnt['a'-'a'] < ans {
		ans = cnt['a'-'a']
	}
	if cnt['l'-'a']/2 < ans {
		ans = cnt['l'-'a'] / 2
	}
	if cnt['o'-'a']/2 < ans {
		ans = cnt['o'-'a'] / 2
	}
	if cnt['n'-'a'] < ans {
		ans = cnt['n'-'a']
	}

	return ans
}
