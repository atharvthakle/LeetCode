func isCircularSentence(sentence string) bool {
    n := len(sentence)
    
    // First and last character must match
    if sentence[0] != sentence[n-1] {
        return false
    }
    
    // Check every word boundary
    for i := 0; i < n; i++ {
        if sentence[i] == ' ' {
            if sentence[i-1] != sentence[i+1] {
                return false
            }
        }
    }
    
    return true
}
