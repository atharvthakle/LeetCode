class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();

        // Mark visited indices by negating
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;  // map number to index
            if (nums[index] > 0)
                nums[index] = -nums[index];
        }

        // Collect indices which remain positive → missing numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                result.push_back(i + 1);
        }

        return result;
    }
};
