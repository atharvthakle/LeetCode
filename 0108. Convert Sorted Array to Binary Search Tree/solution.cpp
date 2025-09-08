class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr; // base case

        int mid = left + (right - left) / 2; // choose middle element
        TreeNode* root = new TreeNode(nums[mid]);

        // recursively build left and right subtrees
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
