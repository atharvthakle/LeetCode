public class Solution {
    public int LongestSubstring(string s, int k) {
        return Helper(s, 0, s.Length, k);
    }

    private int Helper(string s, int start, int end, int k) {
        if (end - start < k) return 0; // too short to satisfy condition

        int[] freq = new int[26];
        for (int i = start; i < end; i++) {
            freq[s[i] - 'a']++;
        }

        for (int mid = start; mid < end; mid++) {
            if (freq[s[mid] - 'a'] < k) {
                // split at invalid character
                int left = Helper(s, start, mid, k);
                int right = Helper(s, mid + 1, end, k);
                return Math.Max(left, right);
            }
        }

        // whole substring valid
        return end - start;
    }
}
