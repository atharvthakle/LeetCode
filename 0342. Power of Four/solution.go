func isPowerOfFour(n int) bool {
    if n <= 0 {
        return false
    }
    // Check power of two AND bit in even position
    return (n&(n-1)) == 0 && (n&0x55555555) != 0
}
