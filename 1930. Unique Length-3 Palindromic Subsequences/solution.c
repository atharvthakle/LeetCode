int countPalindromicSubsequence(char* s) {
    int n = strlen(s);
    int first[26], last[26];
    
    // Initialize first to +inf and last to -inf
    for (int i = 0; i < 26; i++) {
        first[i] = n;
        last[i] = -1;
    }

    // Record first and last occurrences
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (i < first[c]) first[c] = i;
        if (i > last[c])  last[c] = i;
    }

    int result = 0;

    // For each possible outer character
    for (int c = 0; c < 26; c++) {
        if (first[c] < last[c]) {

            int freq[26] = {0};

            // Count distinct characters between first[c] and last[c]
            for (int i = first[c] + 1; i < last[c]; i++) {
                freq[s[i] - 'a'] = 1;
            }

            // Sum distinct characters as middle positions
            for (int x = 0; x < 26; x++) {
                result += freq[x];
            }
        }
    }

    return result;
}
