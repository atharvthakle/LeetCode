class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Define keyboard rows
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        
        // Map each character to its row
        unordered_map<char, int> rowMap;
        for (char c : row1) rowMap[c] = rowMap[toupper(c)] = 1;
        for (char c : row2) rowMap[c] = rowMap[toupper(c)] = 2;
        for (char c : row3) rowMap[c] = rowMap[toupper(c)] = 3;
        
        vector<string> result;
        
        for (string& word : words) {
            int row = rowMap[word[0]];
            bool valid = true;
            for (char c : word) {
                if (rowMap[c] != row) {
                    valid = false;
                    break;
                }
            }
            if (valid) result.push_back(word);
        }
        
        return result;
    }
};
