public class Solution {
    public long MaxProfit(int[] prices, int[] strategy, int k) {
        int n = prices.Length;
        int half = k / 2;

        // 1. Base profit
        long baseProfit = 0;
        for (int i = 0; i < n; i++) {
            baseProfit += (long)strategy[i] * prices[i];
        }

        // Prefix sum of original contribution
        long[] pref = new long[n + 1];
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (long)strategy[i] * prices[i];
        }

        // Prefix sum of prices (used for new profit)
        long[] pricePref = new long[n + 1];
        for (int i = 0; i < n; i++) {
            pricePref[i + 1] = pricePref[i] + prices[i];
        }

        long maxGain = 0;

        // 2. Try all windows of size k
        for (int l = 0; l + k <= n; l++) {
            int mid = l + half;
            int r = l + k;

            // Old profit in window
            long oldProfit = pref[r] - pref[l];

            // New profit:
            // First half → 0
            // Second half → sell (price)
            long newProfit = pricePref[r] - pricePref[mid];

            long gain = newProfit - oldProfit;
            if (gain > maxGain) maxGain = gain;
        }

        return baseProfit + maxGain;
    }
}
