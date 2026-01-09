func canConstruct(ransomNote string, magazine string) bool {
    counts := make([]int, 26)

    // Count letters in magazine
    for _, c := range magazine {
        counts[c-'a']++
    }

    // Use letters for ransomNote
    for _, c := range ransomNote {
        counts[c-'a']--
        if counts[c-'a'] < 0 {
            return false
        }
    }

    return true
}
