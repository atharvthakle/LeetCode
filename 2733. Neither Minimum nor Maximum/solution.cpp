class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() <= 2) return -1;  // no middle value exists

        int mn = INT_MAX, mx = INT_MIN;
        for (int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }

        for (int num : nums) {
            if (num != mn && num != mx)
                return num;  // return any number that is neither min nor max
        }

        return -1;  // fallback, though logically shouldn't reach here
    }
};
