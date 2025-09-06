class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            result.push_back(node->val);

            // Push right first so left is processed first
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }

        return result;
    }
};
