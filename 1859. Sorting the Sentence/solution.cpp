class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10); // max 9 words, so size 10 is enough
        string word = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                int pos = word.back() - '0'; // last char is digit
                word.pop_back(); // remove digit
                words[pos] = word;
                word = "";
            } else {
                word += s[i];
            }
        }
        // handle the last word
        int pos = word.back() - '0';
        word.pop_back();
        words[pos] = word;
        
        // build final sentence
        string result = "";
        for (int i = 1; i < 10; i++) {
            if (!words[i].empty()) {
                if (!result.empty()) result += " ";
                result += words[i];
            }
        }
        return result;
    }
};
