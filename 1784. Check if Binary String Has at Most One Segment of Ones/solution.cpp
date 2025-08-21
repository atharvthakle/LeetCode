class Solution {
public:
    bool checkOnesSegment(string s) {
        // If we ever find "01" in the string, and a '1' after it,
        // then ones are not contiguous.
        return s.find("01") == string::npos;
    }
};
