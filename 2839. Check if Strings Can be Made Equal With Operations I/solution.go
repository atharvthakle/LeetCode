func canBeEqual(s1 string, s2 string) bool {
    // group 1: indices 0,2
    g1 := []byte{s1[0], s1[2]}
    g2 := []byte{s2[0], s2[2]}

    // group 2: indices 1,3
    g3 := []byte{s1[1], s1[3]}
    g4 := []byte{s2[1], s2[3]}

    // sort and compare
    sort.Slice(g1, func(i, j int) bool { return g1[i] < g1[j] })
    sort.Slice(g2, func(i, j int) bool { return g2[i] < g2[j] })
    sort.Slice(g3, func(i, j int) bool { return g3[i] < g3[j] })
    sort.Slice(g4, func(i, j int) bool { return g4[i] < g4[j] })

    return string(g1) == string(g2) && string(g3) == string(g4)
}
