class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A power of two has exactly one bit set in its binary representation.
        // For example: 1 (0001), 2 (0010), 4 (0100), 8 (1000)
        return n > 0 && (n & (n - 1)) == 0;
    }
};
