using System.Text;
using System.Collections.Generic;

public class Solution {
    public string DecodeString(string s) {
        Stack<int> countStack = new Stack<int>();
        Stack<StringBuilder> stringStack = new Stack<StringBuilder>();
        
        StringBuilder current = new StringBuilder();
        int k = 0;
        
        foreach (char c in s) {
            if (char.IsDigit(c)) {
                // Build multi-digit number
                k = k * 10 + (c - '0');
            }
            else if (c == '[') {
                // Push current context
                countStack.Push(k);
                stringStack.Push(current);
                // Reset for new bracket content
                current = new StringBuilder();
                k = 0;
            }
            else if (c == ']') {
                int repeat = countStack.Pop();
                StringBuilder prev = stringStack.Pop();
                
                for (int i = 0; i < repeat; i++) {
                    prev.Append(current);
                }
                
                current = prev;
            }
            else {
                // Normal character
                current.Append(c);
            }
        }
        
        return current.ToString();
    }
}
