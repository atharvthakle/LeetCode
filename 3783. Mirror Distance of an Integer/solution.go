func mirrorDistance(n int) int {
    // reverse the number
    rev := 0
    temp := n
    
    for temp > 0 {
        rev = rev*10 + temp%10
        temp /= 10
    }
    
    // absolute difference
    if n > rev {
        return n - rev
    }
    return rev - n
}
