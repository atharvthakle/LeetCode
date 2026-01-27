func toHex(num int) string {
    if num == 0 {
        return "0"
    }
    
    // Map for hex digits
    hex := "0123456789abcdef"
    
    // Treat number as unsigned 32-bit
    n := uint32(num)
    
    res := ""
    for n > 0 {
        digit := n & 15 // last 4 bits
        res = string(hex[digit]) + res
        n >>= 4
    }
    
    return res
}
