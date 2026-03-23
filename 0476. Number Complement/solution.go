func findComplement(num int) int {
    mask := 0
    temp := num

    for temp > 0 {
        mask = (mask << 1) | 1
        temp >>= 1
    }

    return num ^ mask
}
