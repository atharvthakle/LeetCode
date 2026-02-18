using System.Text;

public class Solution {
    public string OriginalDigits(string s) {
        int[] letterCount = new int[26];
        foreach (char c in s) {
            letterCount[c - 'a']++;
        }

        int[] digitCount = new int[10];

        // Unique letters
        digitCount[0] = letterCount['z' - 'a']; // zero
        digitCount[2] = letterCount['w' - 'a']; // two
        digitCount[4] = letterCount['u' - 'a']; // four
        digitCount[6] = letterCount['x' - 'a']; // six
        digitCount[8] = letterCount['g' - 'a']; // eight

        // Deduce others
        digitCount[3] = letterCount['h' - 'a'] - digitCount[8]; // three
        digitCount[5] = letterCount['f' - 'a'] - digitCount[4]; // five
        digitCount[7] = letterCount['s' - 'a'] - digitCount[6]; // seven
        digitCount[1] = letterCount['o' - 'a'] - digitCount[0] - digitCount[2] - digitCount[4]; // one
        digitCount[9] = letterCount['i' - 'a'] - digitCount[5] - digitCount[6] - digitCount[8]; // nine

        // Build result
        StringBuilder result = new StringBuilder();
        for (int digit = 0; digit <= 9; digit++) {
            for (int i = 0; i < digitCount[digit]; i++) {
                result.Append(digit);
            }
        }

        return result.ToString();
    }
}
