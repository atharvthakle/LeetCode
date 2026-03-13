using System.Text;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public string FrequencySort(string s) {
        var freq = new Dictionary<char, int>();

        foreach (char c in s) {
            if (!freq.ContainsKey(c))
                freq[c] = 0;
            freq[c]++;
        }

        var sorted = freq.OrderByDescending(x => x.Value);

        StringBuilder result = new StringBuilder();

        foreach (var kv in sorted) {
            result.Append(new string(kv.Key, kv.Value));
        }

        return result.ToString();
    }
}
