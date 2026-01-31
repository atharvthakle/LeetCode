func nextGreatestLetter(letters []byte, target byte) byte {
    left, right := 0, len(letters)-1

    for left <= right {
        mid := left + (right-left)/2
        if letters[mid] <= target {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    // If left is out of bounds, wrap around
    if left == len(letters) {
        return letters[0]
    }
    return letters[left]
}
