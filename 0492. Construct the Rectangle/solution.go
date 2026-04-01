import "math"

func constructRectangle(area int) []int {
    w := int(math.Sqrt(float64(area)))

    for i := w; i >= 1; i-- {
        if area%i == 0 {
            return []int{area / i, i}
        }
    }

    return []int{area, 1}
}
