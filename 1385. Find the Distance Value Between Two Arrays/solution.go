func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
    count := 0

    for _, x := range arr1 {
        valid := true

        for _, y := range arr2 {
            diff := x - y
            if diff < 0 {
                diff = -diff
            }

            if diff <= d {
                valid = false
                break
            }
        }

        if valid {
            count++
        }
    }

    return count
}
