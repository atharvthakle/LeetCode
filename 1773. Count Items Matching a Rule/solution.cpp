class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        // Determine the index based on the rule key
        // "type" -> index 0, "color" -> index 1, "name" -> index 2
        int index;
        if (ruleKey == "type") {
            index = 0;
        } else if (ruleKey == "color") {
            index = 1;
        } else {  // ruleKey == "name"
            index = 2;
        }
      
        // Count items that match the rule
        // For each item, check if the value at the determined index equals ruleValue
        return count_if(items.begin(), items.end(), 
                       [&](const vector<string>& item) { 
                           return item[index] == ruleValue; 
                       });
    }
};
