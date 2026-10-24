func countDaysTogether(arriveAlice string, leaveAlice string, arriveBob string, leaveBob string) int {
    days := [12]int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

    toDay := func(date string) int {
        month := int(date[0]-'0')*10 + int(date[1]-'0')
        day := int(date[3]-'0')*10 + int(date[4]-'0')

        total := day
        for i := 0; i < month-1; i++ {
            total += days[i]
        }
        return total
    }

    start := toDay(arriveAlice)
    if b := toDay(arriveBob); b > start {
        start = b
    }

    end := toDay(leaveAlice)
    if b := toDay(leaveBob); b < end {
        end = b
    }

    if start > end {
        return 0
    }

    return end - start + 1
}
