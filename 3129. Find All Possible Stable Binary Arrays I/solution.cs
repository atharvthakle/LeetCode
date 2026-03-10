public class Solution {
    public int NumberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1000000007;

        long[,] dp0 = new long[zero + 1, one + 1];
        long[,] dp1 = new long[zero + 1, one + 1];

        dp0[0,0] = dp1[0,0] = 1;

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {

                for (int k = 1; k <= limit && k <= i; k++) {
                    dp0[i,j] = (dp0[i,j] + dp1[i-k,j]) % MOD;
                }

                for (int k = 1; k <= limit && k <= j; k++) {
                    dp1[i,j] = (dp1[i,j] + dp0[i,j-k]) % MOD;
                }
            }
        }

        long ans = (dp0[zero,one] + dp1[zero,one]) % MOD;
        return (int)ans;
    }
}
