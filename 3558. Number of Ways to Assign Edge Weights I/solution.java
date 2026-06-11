class Solution {
    private static final long MOD = 1_000_000_007L;

    public int assignEdgeWeights(int[][] edges) {
        int n = edges.length + 1;

        java.util.List<Integer>[] graph = new java.util.ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new java.util.ArrayList<>();
        }

        for (int[] e : edges) {
            int u = e[0], v = e[1];
            graph[u].add(v);
            graph[v].add(u);
        }

        java.util.Queue<Integer> q = new java.util.LinkedList<>();
        boolean[] vis = new boolean[n + 1];

        q.offer(1);
        vis[1] = true;

        int depth = -1;

        while (!q.isEmpty()) {
            int sz = q.size();
            depth++;

            for (int i = 0; i < sz; i++) {
                int u = q.poll();

                for (int v : graph[u]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.offer(v);
                    }
                }
            }
        }

        int pathEdges = depth;

        if (pathEdges == 0) {
            return 0;
        }

        return (int) modPow(2, pathEdges - 1);
    }

    private long modPow(long base, long exp) {
        long res = 1;

        while (exp > 0) {
            if ((exp & 1) == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }
}
