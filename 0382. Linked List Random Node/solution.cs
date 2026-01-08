using System;

public class Solution {
    private ListNode head;
    private Random rand;

    public Solution(ListNode head) {
        this.head = head;
        this.rand = new Random();
    }
    
    public int GetRandom() {
        int result = 0;
        int count = 0;
        ListNode curr = head;

        while (curr != null) {
            count++;
            // Pick current node with probability 1/count
            if (rand.Next(count) == 0) {
                result = curr.val;
            }
            curr = curr.next;
        }

        return result;
    }
}
