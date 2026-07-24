class Solution {
    public int uniqueXorTriplets(int[] nums) {
        final int MAXX = 2048;

        boolean[][] dp = new boolean[4][MAXX];
        dp[0][0] = true;

        boolean[] ans = new boolean[MAXX];

        for (int x : nums) {
            ans[x] = true; // triplets with repeated indices give the element itself

            for (int t = 3; t >= 1; t--) {
                for (int v = 0; v < MAXX; v++) {
                    if (dp[t - 1][v]) {
                        dp[t][v ^ x] = true;
                    }
                }
            }
        }

        for (int v = 0; v < MAXX; v++) {
            if (dp[3][v]) ans[v] = true;
        }

        int res = 0;
        for (boolean b : ans) {
            if (b) res++;
        }
        return res;
    }
}
