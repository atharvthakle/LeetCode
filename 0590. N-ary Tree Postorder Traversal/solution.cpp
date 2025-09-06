class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (!root) return result;

        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            result.push_back(node->val);

            // Push all children onto the stack
            for (Node* child : node->children) {
                if (child) stk.push(child);
            }
        }

        // Reverse to get the correct postorder
        reverse(result.begin(), result.end());
        return result;
    }
};
