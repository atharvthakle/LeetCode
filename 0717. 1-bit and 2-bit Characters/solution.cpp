class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int n = bits.size();
        
        while (i < n - 1) { // stop before the last bit
            if (bits[i] == 1) {
                i += 2; // it's a two-bit character
            } else {
                i += 1; // it's a one-bit character
            }
        }
        
        // If we ended exactly at the last bit, it's a one-bit character
        return i == n - 1;
    }
};
