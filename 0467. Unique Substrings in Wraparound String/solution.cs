public class Solution {
    public int FindSubstringInWraproundString(string s) {
        int[] dp = new int[26];
        int maxLen = 0;

        for (int i = 0; i < s.Length; i++) {
            if (i > 0 && 
               ((s[i] - s[i - 1] == 1) || (s[i - 1] == 'z' && s[i] == 'a'))) {
                maxLen++;
            } else {
                maxLen = 1;
            }

            int idx = s[i] - 'a';
            dp[idx] = Math.Max(dp[idx], maxLen);
        }

        int result = 0;
        foreach (int val in dp)
            result += val;

        return result;
    }
}
