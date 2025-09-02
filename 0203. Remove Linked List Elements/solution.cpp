class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node pointing to the head
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;
        
        // Traverse the list
        while (current->next) {
            if (current->next->val == val) {
                // Remove the node by skipping it
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp; // Free memory
            } else {
                current = current->next;
            }
        }
        
        // Get the new head and free dummy node
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
