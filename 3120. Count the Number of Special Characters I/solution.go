func numberOfSpecialChars(word string) int {
    lower := make(map[rune]bool)
    upper := make(map[rune]bool)

    for _, ch := range word {
        if ch >= 'a' && ch <= 'z' {
            lower[ch] = true
        } else {
            upper[ch-'A'+'a'] = true
        }
    }

    count := 0

    for ch := range lower {
        if upper[ch] {
            count++
        }
    }

    return count
}
