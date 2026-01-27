using System;
using System.Collections.Generic;

public class Solution {
    public int MinCost(int n, int[][] edges) {
        // Build adjacency list
        var graph = new List<(int to, int cost)>[n];
        for (int i = 0; i < n; i++)
            graph[i] = new List<(int, int)>();

        foreach (var e in edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].Add((v, w));       // normal edge
            graph[v].Add((u, 2 * w));   // reversed edge using switch
        }

        // Dijkstra
        var dist = new long[n];
        Array.Fill(dist, long.MaxValue);
        dist[0] = 0;

        var pq = new PriorityQueue<int, long>();
        pq.Enqueue(0, 0);

        while (pq.Count > 0) {
            int node = pq.Dequeue();
            long d = dist[node];

            if (node == n - 1) return (int)d;

            foreach (var (next, cost) in graph[node]) {
                long nd = d + cost;
                if (nd < dist[next]) {
                    dist[next] = nd;
                    pq.Enqueue(next, nd);
                }
            }
        }

        return -1;
    }
}
