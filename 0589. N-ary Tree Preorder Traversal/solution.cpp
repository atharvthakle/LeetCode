class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (!root) return result;

        stack<Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            result.push_back(node->val);

            // Push children in reverse order to process leftmost child first
            for (int i = node->children.size() - 1; i >= 0; --i) {
                if (node->children[i]) stk.push(node->children[i]);
            }
        }

        return result;
    }
};
