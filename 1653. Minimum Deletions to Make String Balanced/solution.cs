public class Solution {
    public int MinimumDeletions(string s) {
        int bCount = 0;      // number of 'b' seen so far
        int deletions = 0;   // minimum deletions needed
        
        foreach (char c in s) {
            if (c == 'b') {
                bCount++;
            } else { // c == 'a'
                // either delete this 'a' OR delete all previous 'b's
                deletions = Math.Min(deletions + 1, bCount);
            }
        }
        
        return deletions;
    }
}
