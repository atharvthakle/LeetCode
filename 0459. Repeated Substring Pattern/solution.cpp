class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        // find s inside doubled but ignoring the first and last character
        return doubled.substr(1, doubled.size() - 2).find(s) != string::npos;
    }
};
