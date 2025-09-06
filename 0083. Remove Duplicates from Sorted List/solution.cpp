class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // Skip the duplicate node
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;  // free memory of removed node
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};
