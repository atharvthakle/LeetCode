public class Solution {
    public int IntegerReplacement(int n) {
        long x = n;  // use long to avoid overflow
        int steps = 0;
        
        while (x != 1) {
            if ((x & 1) == 0) {
                // even
                x >>= 1;
            } else {
                // odd
                if (x == 3 || (x & 3) == 1) {
                    x--;   // prefer decrement
                } else {
                    x++;   // prefer increment
                }
            }
            steps++;
        }
        
        return steps;
    }
}
