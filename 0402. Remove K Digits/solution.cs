public class Solution {
    public string RemoveKdigits(string num, int k) {
        if (k >= num.Length) return "0";

        var stack = new Stack<char>();

        foreach (char c in num) {
            while (stack.Count > 0 && k > 0 && stack.Peek() > c) {
                stack.Pop();
                k--;
            }
            stack.Push(c);
        }

        // If removals remain, remove from end
        while (k > 0) {
            stack.Pop();
            k--;
        }

        // Build result
        var arr = stack.Reverse().ToArray();
        string res = new string(arr).TrimStart('0');

        return res.Length == 0 ? "0" : res;
    }
}
