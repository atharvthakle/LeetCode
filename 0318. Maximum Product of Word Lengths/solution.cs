public class Solution {
    public int MaxProduct(string[] words) {
        int n = words.Length;
        int[] masks = new int[n];
        int[] lengths = new int[n];

        // Build bitmask for each word
        for (int i = 0; i < n; i++) {
            int mask = 0;
            foreach (char c in words[i]) {
                mask |= 1 << (c - 'a');
            }
            masks[i] = mask;
            lengths[i] = words[i].Length;
        }

        int maxProduct = 0;

        // Compare all pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    int product = lengths[i] * lengths[j];
                    if (product > maxProduct)
                        maxProduct = product;
                }
            }
        }

        return maxProduct;
    }
}
