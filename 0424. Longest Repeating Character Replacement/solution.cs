public class Solution {
    public int CharacterReplacement(string s, int k) {
        int[] freq = new int[26];
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < s.Length; right++) {
            int idx = s[right] - 'A';
            freq[idx]++;
            
            // track highest frequency in window
            maxFreq = Math.Max(maxFreq, freq[idx]);

            // if replacements needed exceed k, shrink window
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = Math.Max(maxLen, right - left + 1);
        }

        return maxLen;
    }
}
