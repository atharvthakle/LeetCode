/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    // Dummy node to help simplify insertion logic
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* nextNode = curr->next;  // Save next node to process later
        struct ListNode* prev = &dummy;

        // Find the correct place to insert curr
        while (prev->next && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // Insert curr between prev and prev->next
        curr->next = prev->next;
        prev->next = curr;

        // Move to next node in the original list
        curr = nextNode;
    }

    return dummy.next;
}
