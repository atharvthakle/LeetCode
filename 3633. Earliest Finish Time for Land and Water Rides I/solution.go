func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {
	ans := int(1 << 60)

	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}

	for i := 0; i < len(landStartTime); i++ {
		landEnd := landStartTime[i] + landDuration[i]

		for j := 0; j < len(waterStartTime); j++ {
			// Land -> Water
			finish1 := max(landEnd, waterStartTime[j]) + waterDuration[j]
			if finish1 < ans {
				ans = finish1
			}

			// Water -> Land
			waterEnd := waterStartTime[j] + waterDuration[j]
			finish2 := max(waterEnd, landStartTime[i]) + landDuration[i]
			if finish2 < ans {
				ans = finish2
			}
		}
	}

	return ans
}
