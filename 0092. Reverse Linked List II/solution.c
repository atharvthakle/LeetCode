/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    // Create a dummy node to handle edge cases smoothly
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    // Move `prev` to the node just before position `left`
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // `start` will point to the first node of the sublist to reverse
    struct ListNode* start = prev->next;
    struct ListNode* then = start->next;

    // Reverse the sublist between left and right
    for (int i = 0; i < right - left; i++) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy.next;
}
