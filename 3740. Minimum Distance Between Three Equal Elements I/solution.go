func minimumDistance(nums []int) int {
    // map value -> list of indices
    mp := make(map[int][]int)

    for i, v := range nums {
        mp[v] = append(mp[v], i)
    }

    res := int(1e9)

    for _, pos := range mp {
        if len(pos) < 3 {
            continue
        }

        for i := 0; i+2 < len(pos); i++ {
            dist := 2 * (pos[i+2] - pos[i])
            if dist < res {
                res = dist
            }
        }
    }

    if res == int(1e9) {
        return -1
    }
    return res
}
