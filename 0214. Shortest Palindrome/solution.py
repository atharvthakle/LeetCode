class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if not s:
            return s

        rev = s[::-1]
        # Concatenate with a special character to avoid overlap
        combined = s + "#" + rev
        
        # Build LPS (Longest Prefix Suffix) array like in KMP
        lps = [0] * len(combined)
        j = 0
        for i in range(1, len(combined)):
            while j > 0 and combined[i] != combined[j]:
                j = lps[j - 1]
            if combined[i] == combined[j]:
                j += 1
                lps[i] = j
        
        # lps[-1] gives length of longest palindromic prefix
        longest_pref = lps[-1]
        
        # Add the reverse of the remaining suffix in front
        return rev[:len(s) - longest_pref] + s
