public class Solution {
    public int Compress(char[] chars) {
        int n = chars.Length;
        int write = 0;   // where to write compressed data
        int read = 0;    // where to read from
        
        while (read < n) {
            char current = chars[read];
            int count = 0;
            
            // Count consecutive occurrences
            while (read < n && chars[read] == current) {
                read++;
                count++;
            }
            
            // Write character
            chars[write++] = current;
            
            // Write count if > 1
            if (count > 1) {
                foreach (char c in count.ToString()) {
                    chars[write++] = c;
                }
            }
        }
        
        return write;
    }
}
