using System;
using System.Collections.Generic;

public class Solution {
    public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries) {
        // Build graph
        Dictionary<string, List<(string, double)>> graph = new Dictionary<string, List<(string, double)>>();

        for (int i = 0; i < equations.Count; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            if (!graph.ContainsKey(a)) graph[a] = new List<(string, double)>();
            if (!graph.ContainsKey(b)) graph[b] = new List<(string, double)>();

            graph[a].Add((b, val));
            graph[b].Add((a, 1.0 / val));
        }

        double[] result = new double[queries.Count];

        for (int i = 0; i < queries.Count; i++) {
            string start = queries[i][0];
            string end = queries[i][1];

            if (!graph.ContainsKey(start) || !graph.ContainsKey(end)) {
                result[i] = -1.0;
            } else if (start == end) {
                result[i] = 1.0;
            } else {
                HashSet<string> visited = new HashSet<string>();
                result[i] = DFS(start, end, 1.0, graph, visited);
            }
        }

        return result;
    }

    private double DFS(string current, string target, double product,
                       Dictionary<string, List<(string, double)>> graph,
                       HashSet<string> visited) {
        if (current == target) return product;

        visited.Add(current);

        foreach (var (next, weight) in graph[current]) {
            if (!visited.Contains(next)) {
                double res = DFS(next, target, product * weight, graph, visited);
                if (res != -1.0) return res;
            }
        }

        return -1.0;
    }
}
