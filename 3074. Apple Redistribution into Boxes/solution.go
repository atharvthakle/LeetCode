import "sort"

func minimumBoxes(apple []int, capacity []int) int {
    totalApples := 0
    for _, a := range apple {
        totalApples += a
    }

    // Sort capacities in descending order
    sort.Slice(capacity, func(i, j int) bool {
        return capacity[i] > capacity[j]
    })

    usedCapacity := 0
    boxes := 0

    for _, cap := range capacity {
        usedCapacity += cap
        boxes++
        if usedCapacity >= totalApples {
            return boxes
        }
    }

    return boxes
}
