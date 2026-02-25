using System.Collections.Generic;

public class Solution {
    public IList<int> FindAnagrams(string s, string p) {
        List<int> result = new List<int>();
        if (s.Length < p.Length) return result;

        int[] count = new int[26];

        // Build frequency map for p
        foreach (char c in p) {
            count[c - 'a']++;
        }

        int left = 0, right = 0;
        int needed = p.Length;

        while (right < s.Length) {
            // Include current character
            if (count[s[right] - 'a'] > 0) {
                needed--;
            }

            count[s[right] - 'a']--;
            right++;

            // If window size equals p.Length
            if (right - left == p.Length) {
                if (needed == 0) {
                    result.Add(left);
                }

                // Remove left character from window
                if (count[s[left] - 'a'] >= 0) {
                    needed++;
                }

                count[s[left] - 'a']++;
                left++;
            }
        }

        return result;
    }
}
