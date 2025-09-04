class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;
        int n = s.size();
        int start = 0;  // start index of current group
        
        for (int i = 1; i <= n; i++) {
            // check if group ends (either end of string or char changes)
            if (i == n || s[i] != s[start]) {
                int length = i - start;
                if (length >= 3) {
                    result.push_back({start, i - 1});
                }
                start = i;  // move start to new group
            }
        }
        
        return result;
    }
};
