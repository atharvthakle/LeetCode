func minBitwiseArray(nums []int) []int {
    ans := make([]int, len(nums))
    
    for i, y := range nums {
        // count trailing ones
        t := 0
        temp := y
        for temp&1 == 1 {
            t++
            temp >>= 1
        }
        
        if t == 0 {
            ans[i] = -1
            continue
        }
        
        k := t - 1
        x := y & ^(1 << k)
        ans[i] = x
    }
    
    return ans
}
