class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        // Split string s into words
        while (ss >> word) {
            words.push_back(word);
        }
        
        // If pattern length != number of words, cannot match
        if (pattern.size() != words.size()) return false;
        
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            // Check if pattern char already mapped
            if (charToWord.count(c) && charToWord[c] != w)
                return false;
            
            // Check if word already mapped to another char
            if (wordToChar.count(w) && wordToChar[w] != c)
                return false;
            
            // Create the mappings
            charToWord[c] = w;
            wordToChar[w] = c;
        }
        
        return true;
    }
};
