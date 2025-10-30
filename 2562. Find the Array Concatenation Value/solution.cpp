class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        long long result = 0;
        
        while (i <= j) {
            if (i == j) {
                result += nums[i];
            } else {
                string concat = to_string(nums[i]) + to_string(nums[j]);
                result += stoll(concat);
            }
            i++;
            j--;
        }
        
        return result;
    }
};
