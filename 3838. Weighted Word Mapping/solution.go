func mapWordWeights(words []string, weights []int) string {
	res := make([]byte, 0, len(words))

	for _, word := range words {
		sum := 0

		for _, ch := range word {
			sum += weights[ch-'a']
		}

		mod := sum % 26
		res = append(res, byte('z'-mod))
	}

	return string(res)
}
