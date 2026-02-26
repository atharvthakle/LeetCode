using System.Collections.Generic;

public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        Stack<int> s1 = new Stack<int>();
        Stack<int> s2 = new Stack<int>();

        // Push digits into stacks
        while (l1 != null) {
            s1.Push(l1.val);
            l1 = l1.next;
        }

        while (l2 != null) {
            s2.Push(l2.val);
            l2 = l2.next;
        }

        int carry = 0;
        ListNode head = null;

        // Process stacks
        while (s1.Count > 0 || s2.Count > 0 || carry > 0) {
            int sum = carry;

            if (s1.Count > 0) sum += s1.Pop();
            if (s2.Count > 0) sum += s2.Pop();

            carry = sum / 10;

            // Insert new node at front
            ListNode node = new ListNode(sum % 10);
            node.next = head;
            head = node;
        }

        return head;
    }
}
