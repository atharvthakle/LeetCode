class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int insertPos = 0; // Position to insert the next non-zero element

        // Move all non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[insertPos++] = nums[i];
            }
        }

        // Fill the remaining positions with zeros
        while (insertPos < n) {
            nums[insertPos++] = 0;
        }
    }
};
