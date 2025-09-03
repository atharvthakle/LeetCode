class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0); // ASCII for all uppercase + lowercase letters

        for (char c : s) {
            freq[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (int count : freq) {
            if (count % 2 == 0) {
                length += count;
            } else {
                length += count - 1; // use even part
                hasOdd = true;       // keep note that we saw an odd
            }
        }

        if (hasOdd) length += 1; // one odd char in the middle

        return length;
    }
};
