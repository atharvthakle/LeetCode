func canAliceWin(n int) bool {
    stones := 10
    aliceTurn := true

    for n >= stones {
        n -= stones
        stones--
        aliceTurn = !aliceTurn
    }

    return !aliceTurn
}
