#include <string>
using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            int d1 = s[i] - '0';
            int d2 = s[i + 1] - '0';
            if ((d1 % 2 == d2 % 2) && (d1 > d2)) {
                swap(s[i], s[i + 1]);
                break; // only one swap allowed
            }
        }
        return s;
    }
};
