/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    // Copy the data from the next node into the current node
    node->val = node->next->val;
    
    // Bypass the next node
    struct ListNode* temp = node->next;
    node->next = node->next->next;

    // Free the bypassed node (optional for LeetCode, but good practice)
    free(temp);
}
