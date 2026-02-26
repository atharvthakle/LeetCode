public class Solution {
    public int NumSteps(string s) {
        int steps = 0;
        int carry = 0;

        // Start from rightmost bit (ignore MSB at index 0)
        for (int i = s.Length - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;

            if (bit == 1) {
                // odd → add 1 + divide
                steps += 2;
                carry = 1;
            } else {
                // even → divide
                steps += 1;
                // carry stays same
            }
        }

        // If there's leftover carry, one extra step
        return steps + carry;
    }
}
