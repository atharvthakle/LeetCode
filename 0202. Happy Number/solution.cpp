class Solution {
public:
    // Function to get the sum of squares of digits of n
    int sumOfSquares(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        
        do {
            slow = sumOfSquares(slow);           // move slow by 1 step
            fast = sumOfSquares(sumOfSquares(fast)); // move fast by 2 steps
        } while (slow != fast); // detect cycle

        return slow == 1; // if cycle meets at 1 → happy
    }
};
