public class Solution {
    public int LengthLongestPath(string input) {
        int maxLen = 0;
        // lenAtDepth[d] = total length of path up to depth d
        int[] lenAtDepth = new int[input.Length + 1];

        string[] lines = input.Split('\n');

        foreach (string line in lines) {
            int depth = 0;
            int i = 0;
            // Count tabs to get depth
            while (i < line.Length && line[i] == '\t') {
                depth++;
                i++;
            }

            string name = line.Substring(i);
            bool isFile = name.Contains(".");

            if (isFile) {
                int totalLen = lenAtDepth[depth] + name.Length;
                maxLen = Math.Max(maxLen, totalLen);
            } else {
                // +1 accounts for '/' in path
                lenAtDepth[depth + 1] = lenAtDepth[depth] + name.Length + 1;
            }
        }

        return maxLen;
    }
}
