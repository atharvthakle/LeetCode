/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL; // no cycle possible

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Step 1: Detect if a cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // cycle detected
            // Step 2: Find the start of the cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // cycle start node
        }
    }

    return NULL; // no cycle
}
