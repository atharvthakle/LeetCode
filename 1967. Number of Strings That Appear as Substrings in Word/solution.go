import "strings"

func numOfStrings(patterns []string, word string) int {
	count := 0

	for _, p := range patterns {
		if strings.Contains(word, p) {
			count++
		}
	}

	return count
}
