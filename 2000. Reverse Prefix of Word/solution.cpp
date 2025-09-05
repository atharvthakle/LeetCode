#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch);  // find first occurrence
        if (idx == string::npos)  // if not found
            return word;

        reverse(word.begin(), word.begin() + idx + 1);  // reverse prefix
        return word;
    }
};
