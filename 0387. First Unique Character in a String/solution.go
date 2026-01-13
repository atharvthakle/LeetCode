func firstUniqChar(s string) int {
    freq := make([]int, 26)

    // Count frequency
    for i := 0; i < len(s); i++ {
        freq[s[i]-'a']++
    }

    // Find first character with frequency 1
    for i := 0; i < len(s); i++ {
        if freq[s[i]-'a'] == 1 {
            return i
        }
    }

    return -1
}
