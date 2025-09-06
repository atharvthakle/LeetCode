class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters on the left
            while (left < right && !isalnum(s[left])) left++;
            // Skip non-alphanumeric characters on the right
            while (left < right && !isalnum(s[right])) right--;

            // Compare characters in lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
