class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort ascending
        int n = nums.size();
        
        // Check from largest to smallest
        for (int i = n - 1; i >= 2; i--) {
            int a = nums[i - 2], b = nums[i - 1], c = nums[i];
            if (a + b > c) {  // valid triangle
                return a + b + c;
            }
        }
        
        return 0;  // no valid triangle
    }
};
