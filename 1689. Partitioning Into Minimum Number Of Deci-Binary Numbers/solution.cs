public class Solution {
    public int MinPartitions(string n) {
        int maxDigit = 0;
        
        foreach (char c in n) {
            maxDigit = Math.Max(maxDigit, c - '0');
            
            // Early exit: can't exceed 9
            if (maxDigit == 9)
                return 9;
        }
        
        return maxDigit;
    }
}
