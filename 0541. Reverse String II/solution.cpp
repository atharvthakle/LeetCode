#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            // Reverse from i to i+k-1, but not beyond n
            int j = min(i + k, n);
            reverse(s.begin() + i, s.begin() + j);
        }
        return s;
    }
};
