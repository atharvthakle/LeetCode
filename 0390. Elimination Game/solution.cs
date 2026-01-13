public class Solution {
    public int LastRemaining(int n) {
        int head = 1;
        int step = 1;
        int remaining = n;
        bool left = true;
        
        while (remaining > 1) {
            // Move head if eliminating from left,
            // or from right when count is odd
            if (left || (remaining % 2 == 1)) {
                head += step;
            }
            
            remaining /= 2;
            step *= 2;
            left = !left;
        }
        
        return head;
    }
}
