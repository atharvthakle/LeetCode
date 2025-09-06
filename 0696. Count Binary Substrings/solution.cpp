class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1, ans = 0;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                curr++;  // extend current group
            } else {
                ans += min(prev, curr);  // add pairs from previous and current group
                prev = curr;  // update previous group length
                curr = 1;     // reset current group length
            }
        }
        
        ans += min(prev, curr); // add the last group pair
        return ans;
    }
};
