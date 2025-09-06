/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Iterative approach
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next; // store next node
            curr->next = prev;               // reverse the link
            prev = curr;                     // move prev forward
            curr = nextTemp;                 // move curr forward
        }
        return prev;
    }
    
    // Recursive approach
    ListNode* reverseListRecursive(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    // Default function using iterative method
    ListNode* reverseList(ListNode* head) {
        return reverseListIterative(head);
        // Or, use recursive:
        // return reverseListRecursive(head);
    }
};
