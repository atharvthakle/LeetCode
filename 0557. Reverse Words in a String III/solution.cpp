class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] == ' ') {
                // reverse from start to i-1
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1; // move start to next word
            }
        }
        
        return s;
    }
};
