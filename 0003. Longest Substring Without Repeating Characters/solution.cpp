#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1); // store last index of each char (ASCII range)
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            
            if (lastSeen[c] >= left) {
                // character repeated inside window
                left = lastSeen[c] + 1;
            }
            
            lastSeen[c] = right; // update last seen position
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
