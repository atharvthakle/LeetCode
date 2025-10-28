class Solution {
public:
    bool simulate(vector<int> nums, int start, int dir) {
        int n = nums.size();
        int curr = start;
        
        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += dir; // move in same direction
            } else {
                nums[curr]--; // decrement
                dir = -dir;   // reverse direction
                curr += dir;  // move in new direction
            }
        }

        // check if all elements became zero
        for (int x : nums) {
            if (x != 0) return false;
        }
        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // Try both left (-1) and right (+1) directions
                if (simulate(nums, i, -1)) ans++;
                if (simulate(nums, i, 1)) ans++;
            }
        }

        return ans;
    }
};
