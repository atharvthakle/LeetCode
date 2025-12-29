public class Solution {
    private Dictionary<string, List<char>> map = new();
    private HashSet<string> bad = new();

    public bool PyramidTransition(string bottom, IList<string> allowed) {
        // Build mapping: "AB" -> [C, D, ...]
        foreach (var s in allowed) {
            string key = s.Substring(0, 2);
            char top = s[2];
            if (!map.ContainsKey(key))
                map[key] = new List<char>();
            map[key].Add(top);
        }

        return Dfs(bottom);
    }

    private bool Dfs(string cur) {
        if (cur.Length == 1)
            return true;

        if (bad.Contains(cur))
            return false;

        var nextRows = new List<string>();
        BuildNextRows(cur, 0, new char[cur.Length - 1], nextRows);

        foreach (var next in nextRows) {
            if (Dfs(next))
                return true;
        }

        bad.Add(cur);
        return false;
    }

    private void BuildNextRows(string cur, int idx, char[] path, List<string> res) {
        if (idx == cur.Length - 1) {
            res.Add(new string(path));
            return;
        }

        string key = cur.Substring(idx, 2);
        if (!map.ContainsKey(key))
            return;

        foreach (char c in map[key]) {
            path[idx] = c;
            BuildNextRows(cur, idx + 1, path, res);
        }
    }
}
