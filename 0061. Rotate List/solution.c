/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Find length of the list
    int length = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Step 2: Connect tail to head (make it circular)
    tail->next = head;

    // Step 3: Find new head position
    k = k % length;
    int stepsToNewHead = length - k;

    struct ListNode* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    // Step 4: Break the circle
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
