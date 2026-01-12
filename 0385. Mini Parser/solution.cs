public class Solution {
    public NestedInteger Deserialize(string s) {
        // Case: single integer
        if (s[0] != '[') {
            return new NestedInteger(int.Parse(s));
        }
        
        Stack<NestedInteger> stack = new Stack<NestedInteger>();
        NestedInteger current = null;
        int i = 0;
        
        while (i < s.Length) {
            char c = s[i];
            
            if (c == '[') {
                // Start new list
                NestedInteger ni = new NestedInteger();
                if (stack.Count > 0) {
                    stack.Peek().Add(ni);
                }
                stack.Push(ni);
                i++;
            }
            else if (c == ']') {
                current = stack.Pop();
                i++;
            }
            else if (c == ',') {
                i++;
            }
            else {
                // Parse integer (could be negative)
                int start = i;
                while (i < s.Length && (char.IsDigit(s[i]) || s[i] == '-')) {
                    i++;
                }
                int val = int.Parse(s.Substring(start, i - start));
                stack.Peek().Add(new NestedInteger(val));
            }
        }
        
        return current;
    }
}
