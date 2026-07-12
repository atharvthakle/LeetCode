import "sort"

func arrayRankTransform(arr []int) []int {
	n := len(arr)
	if n == 0 {
		return []int{}
	}

	sorted := make([]int, n)
	copy(sorted, arr)
	sort.Ints(sorted)

	rank := make(map[int]int)
	r := 1
	for _, x := range sorted {
		if _, exists := rank[x]; !exists {
			rank[x] = r
			r++
		}
	}

	ans := make([]int, n)
	for i, x := range arr {
		ans[i] = rank[x]
	}

	return ans
}
