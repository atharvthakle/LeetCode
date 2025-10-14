class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Iterate through possible starting points for the first subarray
        for (int i = 0; i + 2 * k <= n; i++) {
            bool firstInc = true, secondInc = true;

            // Check if first subarray [i .. i + k - 1] is strictly increasing
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    firstInc = false;
                    break;
                }
            }

            // If first subarray fails, skip to next i
            if (!firstInc) continue;

            // Check if second subarray [i + k .. i + 2*k - 1] is strictly increasing
            for (int j = i + k + 1; j < i + 2 * k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    secondInc = false;
                    break;
                }
            }

            // If both subarrays are strictly increasing, return true
            if (secondInc) return true;
        }

        return false;
    }
};  
