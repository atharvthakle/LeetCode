class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Precomputed primes up to 20 (max bits in 10^6)
        // 2,3,5,7,11,13,17,19 are primes
        int prime_mask = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7) |
                         (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19);
        
        int count = 0;
        for (int num = left; num <= right; ++num) {
            int set_bits = __builtin_popcount(num);  // count 1s in binary
            if (prime_mask & (1 << set_bits)) {
                count++;
            }
        }
        return count;
    }
};
