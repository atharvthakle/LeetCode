class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while (curr != nullptr || !stk.empty()) {
            // Go as left as possible
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            // Process node
            curr = stk.top();
            stk.pop();
            result.push_back(curr->val);
            // Move to right subtree
            curr = curr->right;
        }

        return result;
    }
};
