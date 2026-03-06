func minOperations(s string) int {
    mismatch1 := 0 // pattern starting with '0'
    mismatch2 := 0 // pattern starting with '1'
    
    for i := 0; i < len(s); i++ {
        if i%2 == 0 {
            if s[i] != '0' {
                mismatch1++
            }
            if s[i] != '1' {
                mismatch2++
            }
        } else {
            if s[i] != '1' {
                mismatch1++
            }
            if s[i] != '0' {
                mismatch2++
            }
        }
    }
    
    if mismatch1 < mismatch2 {
        return mismatch1
    }
    return mismatch2
}
