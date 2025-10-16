#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int expected = 0;
        for (int f : freq) {
            if (f > 0) {
                if (expected == 0) expected = f;
                else if (f != expected) return false;
            }
        }

        return true;
    }
};
