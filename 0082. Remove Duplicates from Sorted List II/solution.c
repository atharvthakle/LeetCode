/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Dummy node helps handle head duplicates easily
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy; // points to the last node known to be unique
    struct ListNode* curr = head;

    while (curr) {
        // Check if current node is a start of duplicates
        if (curr->next && curr->val == curr->next->val) {
            int duplicate_val = curr->val;
            // Skip all nodes with this duplicate value
            while (curr && curr->val == duplicate_val) {
                struct ListNode* tmp = curr;
                curr = curr->next;
                // optional: free(tmp); // only if you want to free memory
            }
            prev->next = curr; // link past all duplicates
        } else {
            // current node is unique so far
            prev = curr;
            curr = curr->next;
        }
    }

    return dummy.next;
}
