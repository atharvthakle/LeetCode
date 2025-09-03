class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string> seen;
        int count = 0;
        
        for (auto &w : words) {
            string rev = w;
            reverse(rev.begin(), rev.end());
            
            if (seen.count(rev)) {
                count++;
                seen.erase(rev); // use up the pair
            } else {
                seen.insert(w);
            }
        }
        return count;
    }
};
