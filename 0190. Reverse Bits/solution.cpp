class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;          // shift result left to make space
            result |= (n & 1);     // add the last bit of n
            n >>= 1;               // shift n right
        }
        return result;
    }
};
