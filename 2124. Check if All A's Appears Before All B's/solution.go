func checkString(s string) bool {
    seenB := false

    for i := 0; i < len(s); i++ {
        if s[i] == 'b' {
            seenB = true
        } else if seenB {
            return false
        }
    }

    return true
}
