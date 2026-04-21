import java.util.*;

class Solution {

    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;
        UnionFind uf = new UnionFind(n);

        // build components
        for (int[] swap : allowedSwaps) {
            uf.union(swap[0], swap[1]);
        }

        // group indices by root
        Map<Integer, List<Integer>> groups = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int root = uf.find(i);
            groups.computeIfAbsent(root, k -> new ArrayList<>()).add(i);
        }

        int res = 0;

        // process each group
        for (List<Integer> group : groups.values()) {
            Map<Integer, Integer> count = new HashMap<>();

            // count source values
            for (int idx : group) {
                count.put(source[idx], count.getOrDefault(source[idx], 0) + 1);
            }

            // match with target
            for (int idx : group) {
                int val = target[idx];
                if (count.getOrDefault(val, 0) > 0) {
                    count.put(val, count.get(val) - 1);
                } else {
                    res++;
                }
            }
        }

        return res;
    }

    // Union-Find
    class UnionFind {
        int[] parent;

        UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void union(int a, int b) {
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                parent[pa] = pb;
            }
        }
    }
}
