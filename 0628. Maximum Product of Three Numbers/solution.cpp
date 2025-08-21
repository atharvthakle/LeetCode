#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort the array
        
        int n = nums.size();
        
        // Option 1: product of last three (largest three)
        int option1 = nums[n-1] * nums[n-2] * nums[n-3];
        
        // Option 2: product of two smallest (negatives) and largest
        int option2 = nums[0] * nums[1] * nums[n-1];
        
        return max(option1, option2);
    }
};
