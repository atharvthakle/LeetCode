class Solution {
public:
    int maxFreqSum(string s) {
        // Frequency array for all 26 lowercase letters
        int freq[26] = {0};
        
        // Count frequencies
        for(char c : s) {
            freq[c - 'a']++;
        }
        
        // Define vowels for quick lookup
        string vowels = "aeiou";
        bool isVowel[26] = {false};
        for(char v : vowels) {
            isVowel[v - 'a'] = true;
        }
        
        int maxVowel = 0, maxConsonant = 0;
        
        // Find maximum among vowels and consonants
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                if(isVowel[i])
                    maxVowel = max(maxVowel, freq[i]);
                else
                    maxConsonant = max(maxConsonant, freq[i]);
            }
        }
        
        return maxVowel + maxConsonant;
    }
};
