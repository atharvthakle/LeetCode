public class Solution {
    public char FindKthBit(int n, int k) {
        if (n == 1) return '0';
        
        int mid = 1 << (n - 1);  // 2^(n-1)
        
        if (k == mid) return '1';
        
        if (k < mid)
            return FindKthBit(n - 1, k);
        
        // k > mid
        int mirror = (1 << n) - k;
        char bit = FindKthBit(n - 1, mirror);
        
        return bit == '0' ? '1' : '0';
    }
}
