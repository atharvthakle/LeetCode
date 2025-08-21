class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOnes = 0, maxZeros = 0;
        int curr = 1;
        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i-1]) {
                curr++;
            } else {
                if(s[i-1] == '1') maxOnes = max(maxOnes, curr);
                else maxZeros = max(maxZeros, curr);
                curr = 1;
            }
        }
        
        // handle last segment
        if(s.back() == '1') maxOnes = max(maxOnes, curr);
        else maxZeros = max(maxZeros, curr);
        
        return maxOnes > maxZeros;
    }
};
