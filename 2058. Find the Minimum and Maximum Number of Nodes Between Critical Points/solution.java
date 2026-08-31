class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int first = -1;
        int last = -1;
        int prevCritical = -1;
        int minDistance = Integer.MAX_VALUE;

        ListNode prev = head;
        ListNode curr = head.next;
        int index = 1;

        while (curr != null && curr.next != null) {
            int prevVal = prev.val;
            int currVal = curr.val;
            int nextVal = curr.next.val;

            if ((currVal > prevVal && currVal > nextVal) ||
                (currVal < prevVal && currVal < nextVal)) {

                if (first == -1) {
                    first = index;
                }

                if (prevCritical != -1) {
                    minDistance = Math.min(minDistance, index - prevCritical);
                }

                prevCritical = index;
                last = index;
            }

            prev = curr;
            curr = curr.next;
            index++;
        }

        if (first == -1 || first == last) {
            return new int[]{-1, -1};
        }

        return new int[]{minDistance, last - first};
    }
}
