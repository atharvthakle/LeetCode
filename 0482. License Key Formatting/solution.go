func licenseKeyFormatting(s string, k int) string {
    res := []byte{}
    count := 0

    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == '-' {
            continue
        }

        // add dash after k chars
        if count == k {
            res = append(res, '-')
            count = 0
        }

        // convert to uppercase
        ch := s[i]
        if ch >= 'a' && ch <= 'z' {
            ch = ch - 'a' + 'A'
        }

        res = append(res, ch)
        count++
    }

    // reverse result
    for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
        res[i], res[j] = res[j], res[i]
    }

    return string(res)
}
