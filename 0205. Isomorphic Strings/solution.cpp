#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapST;  // mapping from s → t
        unordered_map<char, char> mapTS;  // mapping from t → s

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            // If c1 was already mapped, check consistency
            if (mapST.count(c1) && mapST[c1] != c2)
                return false;

            // If c2 was already mapped, check consistency
            if (mapTS.count(c2) && mapTS[c2] != c1)
                return false;

            // Otherwise establish both mappings
            mapST[c1] = c2;
            mapTS[c2] = c1;
        }

        return true;
    }
};
