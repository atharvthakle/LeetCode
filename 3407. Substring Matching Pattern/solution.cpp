class Solution {
public:
    bool hasMatch(string s, string p) {
        // Split pattern into prefix and suffix around '*'
        int star = p.find('*');
        string prefix = p.substr(0, star);
        string suffix = p.substr(star + 1);

        // Now try to find a substring in s that matches
        // Conditions: substring should start with prefix and end with suffix
        for (int i = 0; i + (int)prefix.size() <= s.size(); i++) {
            // Check if prefix matches starting at i
            if (s.substr(i, prefix.size()) == prefix) {
                // Substring starting at i with prefix matches,
                // now check if the rest has suffix
                for (int j = i + prefix.size(); j <= s.size(); j++) {
                    if (j + (int)suffix.size() <= s.size() &&
                        s.substr(j, suffix.size()) == suffix) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
