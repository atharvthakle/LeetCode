class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i > farthest) return false;  // stuck
            farthest = max(farthest, i + nums[i]);
        }
        
        return true;
    }
};
