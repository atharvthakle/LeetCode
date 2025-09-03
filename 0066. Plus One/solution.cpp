class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // just increment and return
                return digits;
            }
            digits[i] = 0;  // carry over
        }
        
        // If we reach here, all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
