class NumArray {
private:
    vector<int> prefixSum;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n + 1, 0);  // prefixSum[0] = 0
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // sum from left to right = prefixSum[right+1] - prefixSum[left]
        return prefixSum[right + 1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
