public class Solution {
    public long MaximumProfit(int[] prices, int k) {
        int n = prices.Length;
        long NEG = long.MinValue / 4;

        long[] dp0 = new long[k + 1];
        long[] dpL = new long[k + 1];
        long[] dpS = new long[k + 1];

        for (int i = 0; i <= k; i++) {
            dp0[i] = NEG;
            dpL[i] = NEG;
            dpS[i] = NEG;
        }

        dp0[0] = 0;

        foreach (int p in prices) {
            long[] ndp0 = (long[])dp0.Clone();
            long[] ndpL = (long[])dpL.Clone();
            long[] ndpS = (long[])dpS.Clone();

            for (int t = 0; t <= k; t++) {
                if (dp0[t] != NEG) {
                    ndpL[t] = Math.Max(ndpL[t], dp0[t] - p); // open long
                    ndpS[t] = Math.Max(ndpS[t], dp0[t] + p); // open short
                }

                if (t + 1 <= k) {
                    if (dpL[t] != NEG)
                        ndp0[t + 1] = Math.Max(ndp0[t + 1], dpL[t] + p); // close long
                    if (dpS[t] != NEG)
                        ndp0[t + 1] = Math.Max(ndp0[t + 1], dpS[t] - p); // close short
                }
            }

            dp0 = ndp0;
            dpL = ndpL;
            dpS = ndpS;
        }

        long ans = 0;
        for (int t = 0; t <= k; t++)
            ans = Math.Max(ans, dp0[t]);

        return ans;
    }
}
