using System.Text;

public class Solution {
    int count = 0;
    string result = "";

    public string GetHappyString(int n, int k) {
        StringBuilder current = new StringBuilder();
        DFS(n, k, current);
        return result;
    }

    private void DFS(int n, int k, StringBuilder current) {
        if (result != "") return;

        if (current.Length == n) {
            count++;
            if (count == k) {
                result = current.ToString();
            }
            return;
        }

        foreach (char c in new char[] { 'a', 'b', 'c' }) {
            if (current.Length > 0 && current[current.Length - 1] == c)
                continue;

            current.Append(c);
            DFS(n, k, current);
            current.Length--;
        }
    }
}
