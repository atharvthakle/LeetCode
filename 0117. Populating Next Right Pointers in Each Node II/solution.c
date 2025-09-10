/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (!root) return NULL;

    struct Node* curr = root;
    struct Node* head = NULL;  // head of next level
    struct Node* prev = NULL;  // previous node on next level

    while (curr) {
        while (curr) {
            if (curr->left) {
                if (prev) {
                    prev->next = curr->left;
                } else {
                    head = curr->left;
                }
                prev = curr->left;
            }
            if (curr->right) {
                if (prev) {
                    prev->next = curr->right;
                } else {
                    head = curr->right;
                }
                prev = curr->right;
            }
            curr = curr->next;  // move along current level
        }
        curr = head;  // move to next level
        head = NULL;
        prev = NULL;
    }

    return root;
}
