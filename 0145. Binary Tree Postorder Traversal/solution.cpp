class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            result.push_back(node->val);

            // Push left child first, then right child
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }

        // Reverse the result to get postorder
        reverse(result.begin(), result.end());
        return result;
    }
};
