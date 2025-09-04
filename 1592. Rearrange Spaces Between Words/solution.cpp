#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int spaceCount = 0;
        for (char c : text) {
            if (c == ' ') spaceCount++;
        }
        
        // Split words
        stringstream ss(text);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        
        int n = words.size();
        if (n == 1) {
            // All spaces go at the end if only one word
            return words[0] + string(spaceCount, ' ');
        }
        
        int spaceBetween = spaceCount / (n - 1);
        int extraSpaces = spaceCount % (n - 1);
        
        string sep(spaceBetween, ' ');
        string result;
        
        for (int i = 0; i < n; i++) {
            result += words[i];
            if (i < n - 1) result += sep;
        }
        result += string(extraSpaces, ' ');
        
        return result;
    }
};
