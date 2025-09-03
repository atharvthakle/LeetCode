class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if (m > n) return -1;  // needle longer than haystack

        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }
        return -1;
    }
};
