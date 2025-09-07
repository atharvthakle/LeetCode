class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count = 0;  // count removals
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                count++;
                if (count > 1) return false;

                // If removing nums[i-1] still keeps it valid
                if (i == 1 || nums[i] > nums[i - 2]) {
                    // ok, pretend nums[i-1] is removed
                    continue;
                }
                // else, we must remove nums[i]
                else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }
};
