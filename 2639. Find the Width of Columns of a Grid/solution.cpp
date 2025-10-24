class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, 0);
        
        for (int j = 0; j < n; j++) {
            int maxLen = 0;
            for (int i = 0; i < m; i++) {
                int val = grid[i][j];
                // Calculate length of number (including '-' if negative)
                int len = to_string(val).size();
                maxLen = max(maxLen, len);
            }
            ans[j] = maxLen;
        }
        return ans;
    }
};
