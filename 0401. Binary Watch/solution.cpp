#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        // Loop through all possible hours (0-11)
        for (int h = 0; h < 12; h++) {
            // Loop through all possible minutes (0-59)
            for (int m = 0; m < 60; m++) {
                // Count number of bits turned on in hour and minute
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    // Format string: hour:min (minutes always 2 digits)
                    string time = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};
