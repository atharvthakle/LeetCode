import "sort"

func minimumCost(cost []int) int {
	sort.Sort(sort.Reverse(sort.IntSlice(cost)))

	ans := 0

	for i := 0; i < len(cost); i++ {
		if i%3 != 2 { // every third candy is free
			ans += cost[i]
		}
	}

	return ans
}
