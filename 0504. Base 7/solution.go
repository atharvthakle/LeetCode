func convertToBase7(num int) string {
    if num == 0 {
        return "0"
    }

    negative := num < 0
    if negative {
        num = -num
    }

    res := ""

    for num > 0 {
        digit := num % 7
        res = string('0'+digit) + res
        num /= 7
    }

    if negative {
        res = "-" + res
    }

    return res
}
