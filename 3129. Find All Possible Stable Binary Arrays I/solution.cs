public class Solution {
    public int NumberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1000000007;

        long[,] dp0 = new long[zero + 1, one + 1];
        long[,] dp1 = new long[zero + 1, one + 1];

        if (zero > 0) dp0[1, 0] = 1;
        if (one > 0) dp1[0, 1] = 1;

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {

                if (i > 0) {
                    dp0[i, j] = (dp0[i, j] + dp1[i - 1, j]) % MOD;

                    if (i - limit - 1 >= 0)
                        dp0[i, j] = (dp0[i, j] - dp1[i - limit - 1, j] + MOD) % MOD;
                }

                if (j > 0) {
                    dp1[i, j] = (dp1[i, j] + dp0[i, j - 1]) % MOD;

                    if (j - limit - 1 >= 0)
                        dp1[i, j] = (dp1[i, j] - dp0[i, j - limit - 1] + MOD) % MOD;
                }
            }
        }

        return (int)((dp0[zero, one] + dp1[zero, one]) % MOD);
    }
}
