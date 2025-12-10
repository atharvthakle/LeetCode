public class Solution {
    public int CountPermutations(int[] complexity) {
        const int MOD = 1_000_000_007;
        int n = complexity.Length;

        // If any other computer has complexity <= complexity[0], impossible.
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        // Otherwise, any permutation of the remaining n-1 computers is valid:
        // answer = (n - 1)! % MOD
        long ans = 1;
        for (int i = 1; i <= n - 1; i++) {
            ans = (ans * i) % MOD;
        }

        return (int)ans;
    }
}
