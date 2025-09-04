class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.size();
        
        for (int i = 0; i < n; i += k) {
            string group = s.substr(i, k); // take k chars (or less if at end)
            
            // if group is shorter than k, pad with fill
            while (group.size() < k) {
                group.push_back(fill);
            }
            
            result.push_back(group);
        }
        
        return result;
    }
};
