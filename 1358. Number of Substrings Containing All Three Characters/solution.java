class Solution {
    public int numberOfSubstrings(String s) {
        int[] cnt = new int[3];
        int left = 0;
        int ans = 0;
        int n = s.length();

        for (int right = 0; right < n; right++) {
            cnt[s.charAt(right) - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += n - right;
                cnt[s.charAt(left) - 'a']--;
                left++;
            }
        }

        return ans;
    }
}
