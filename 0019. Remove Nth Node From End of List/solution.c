/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create dummy node
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;

    // Move fast ahead by n+1 steps
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move fast to the end, maintaining the gap
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove nth node
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete);

    struct ListNode* newHead = dummy->next;
    free(dummy);

    return newHead;
}
