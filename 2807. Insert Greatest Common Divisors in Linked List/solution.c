/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* curr = head;
    while (curr && curr->next) {
        int g = gcd(curr->val, curr->next->val);

        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = g;
        node->next = curr->next;

        curr->next = node;
        curr = node->next;  // move to next original node
    }
    return head;
}
