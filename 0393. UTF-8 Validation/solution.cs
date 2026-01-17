public class Solution {
    public bool ValidUtf8(int[] data) {
        int remaining = 0; // number of continuation bytes expected
        
        foreach (int num in data) {
            int b = num & 0xFF; // only lowest 8 bits matter
            
            if (remaining == 0) {
                // Determine how many bytes this character uses
                if ((b >> 7) == 0b0) {
                    // 1-byte character (0xxxxxxx)
                    continue;
                }
                else if ((b >> 5) == 0b110) {
                    remaining = 1; // 2-byte character
                }
                else if ((b >> 4) == 0b1110) {
                    remaining = 2; // 3-byte character
                }
                else if ((b >> 3) == 0b11110) {
                    remaining = 3; // 4-byte character
                }
                else {
                    return false; // invalid first byte
                }
            } 
            else {
                // Must be continuation byte of form 10xxxxxx
                if ((b >> 6) != 0b10) return false;
                remaining--;
            }
        }
        
        // All characters must be fully completed
        return remaining == 0;
    }
}
