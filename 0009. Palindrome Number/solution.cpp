class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindrome
        if (x < 0) return false;

        // Numbers ending with 0 (but not 0 itself) are not palindrome
        if (x % 10 == 0 && x != 0) return false;

        long long rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10; // add last digit
            x /= 10; // remove last digit
        }

        // For even digits: x == rev
        // For odd digits: x == rev/10 (middle digit ignored)
        return (x == rev || x == rev / 10);
    }
};
