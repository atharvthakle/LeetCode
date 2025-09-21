class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) return res;

        int start = nums[0];  // start of current range

        for (int i = 1; i <= n; i++) {
            // Check if we reached the end OR a break in consecutive numbers
            if (i == n || nums[i] != nums[i - 1] + 1) {
                int end = nums[i - 1];
                if (start == end)
                    res.push_back(to_string(start));
                else
                    res.push_back(to_string(start) + "->" + to_string(end));
                if (i < n) start = nums[i];  // start new range
            }
        }

        return res;
    }
};
