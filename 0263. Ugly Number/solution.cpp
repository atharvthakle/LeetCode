class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false; // negative numbers and 0 are not ugly

        int primes[3] = {2, 3, 5};

        for (int p : primes) {
            while (n % p == 0) {
                n /= p; // divide n by 2, 3, or 5 as long as possible
            }
        }

        return n == 1; // if after division we get 1, it is ugly
    }
};
