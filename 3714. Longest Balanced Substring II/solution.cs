using System;
using System.Collections.Generic;

public class Solution {
    public int LongestBalanced(string s) {
        int ans = 0;

        // Case 1: longest single-character run
        ans = Math.Max(ans, LongestSingleChar(s));

        // Case 2: equal counts of two characters
        ans = Math.Max(ans, LongestTwoChars(s, 'a', 'b'));
        ans = Math.Max(ans, LongestTwoChars(s, 'a', 'c'));
        ans = Math.Max(ans, LongestTwoChars(s, 'b', 'c'));

        // Case 3: equal counts of a, b, c
        ans = Math.Max(ans, LongestThreeChars(s));

        return ans;
    }

    // Longest run of identical characters
    private int LongestSingleChar(string s) {
        int maxLen = 1, cur = 1;
        for (int i = 1; i < s.Length; i++) {
            if (s[i] == s[i - 1]) cur++;
            else cur = 1;
            maxLen = Math.Max(maxLen, cur);
        }
        return maxLen;
    }

    // Longest substring where counts of x and y are equal
    // and no other characters appear
    private int LongestTwoChars(string s, char x, char y) {
        int diff = 0;
        int maxLen = 0;

        var firstSeen = new Dictionary<int, int>();
        firstSeen[0] = -1;

        for (int i = 0; i < s.Length; i++) {
            if (s[i] == x) diff++;
            else if (s[i] == y) diff--;
            else {
                // reset when third character appears
                diff = 0;
                firstSeen.Clear();
                firstSeen[0] = i;
                continue;
            }

            if (firstSeen.ContainsKey(diff)) {
                maxLen = Math.Max(maxLen, i - firstSeen[diff]);
            } else {
                firstSeen[diff] = i;
            }
        }

        return maxLen;
    }

    // Longest substring where counts of a, b, c are equal
    private int LongestThreeChars(string s) {
        int countA = 0, countB = 0, countC = 0;
        int maxLen = 0;

        var map = new Dictionary<(int, int), int>();
        map[(0, 0)] = -1;

        for (int i = 0; i < s.Length; i++) {
            if (s[i] == 'a') countA++;
            else if (s[i] == 'b') countB++;
            else countC++;

            var key = (countA - countB, countA - countC);

            if (map.ContainsKey(key)) {
                maxLen = Math.Max(maxLen, i - map[key]);
            } else {
                map[key] = i;
            }
        }

        return maxLen;
    }
}
