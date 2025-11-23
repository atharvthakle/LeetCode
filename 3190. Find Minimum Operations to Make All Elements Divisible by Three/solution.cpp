class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int num : nums) {
            int r = num % 3;
            ops += min(r, 3 - r); // number of +1 or -1 to make divisible by 3
        }
        return ops;
    }
};
