public class Solution {
    public bool IsValidSerialization(string preorder) {
        int slots = 1; // one slot for the root

        string[] nodes = preorder.Split(',');

        foreach (string node in nodes) {
            // consume one slot
            slots--;
            if (slots < 0) return false;

            // non-null node creates two new slots
            if (node != "#") {
                slots += 2;
            }
        }

        // all slots must be exactly used
        return slots == 0;
    }
}
