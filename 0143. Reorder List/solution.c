/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return;

    // Step 1: Find the middle of the list
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    struct ListNode *prev = NULL, *curr = slow->next, *nextNode;
    slow->next = NULL; // split the list into two halves

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    // 'prev' now points to head of the reversed second half

    // Step 3: Merge the two halves
    struct ListNode *first = head;
    struct ListNode *second = prev;
    struct ListNode *temp1, *temp2;

    while (second != NULL) {
        temp1 = first->next;
        temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}
