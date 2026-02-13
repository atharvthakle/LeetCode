func addStrings(num1 string, num2 string) string {
    i := len(num1) - 1
    j := len(num2) - 1
    carry := 0

    // result stored in reverse order
    result := make([]byte, 0, max(len(num1), len(num2)) + 1)

    for i >= 0 || j >= 0 || carry > 0 {
        sum := carry

        if i >= 0 {
            sum += int(num1[i] - '0')
            i--
        }
        if j >= 0 {
            sum += int(num2[j] - '0')
            j--
        }

        digit := byte(sum%10) + '0'
        result = append(result, digit)
        carry = sum / 10
    }

    // reverse result
    for l, r := 0, len(result)-1; l < r; l, r = l+1, r-1 {
        result[l], result[r] = result[r], result[l]
    }

    return string(result)
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
