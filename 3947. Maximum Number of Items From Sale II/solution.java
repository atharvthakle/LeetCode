import java.util.Arrays;

class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;
        int[] freq = new int[n + 1];

        int minPrice = Integer.MAX_VALUE;

        for (int[] item : items) {
            freq[item[0]]++;
            minPrice = Math.min(minPrice, item[1]);
        }

        int[] divisibleCount = new int[n + 1];

        for (int f = 1; f <= n; f++) {
            int count = 0;

            for (int multiple = f; multiple <= n; multiple += f) {
                count += freq[multiple];
            }

            divisibleCount[f] = count - 1;
        }

        Arrays.sort(items, (a, b) -> Integer.compare(a[1], b[1]));

        long remaining = budget;
        long selected = 0;

        for (int[] item : items) {
            int factor = item[0];
            int price = item[1];
            int capacity = divisibleCount[factor];

            if (capacity == 0 || price > 2L * minPrice) {
                continue;
            }

            long bought = Math.min(capacity, remaining / price);

            selected += bought;
            remaining -= bought * price;
        }

        return (int) (2 * selected + remaining / minPrice);
    }
}
