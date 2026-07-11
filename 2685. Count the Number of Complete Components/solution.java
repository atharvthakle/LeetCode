import java.util.*;

class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        boolean[] visited = new boolean[n];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            List<Integer> component = new ArrayList<>();
            Queue<Integer> queue = new LinkedList<>();
            queue.offer(i);
            visited[i] = true;

            while (!queue.isEmpty()) {
                int u = queue.poll();
                component.add(u);

                for (int v : graph[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        queue.offer(v);
                    }
                }
            }

            int size = component.size();
            boolean complete = true;

            for (int node : component) {
                if (graph[node].size() != size - 1) {
                    complete = false;
                    break;
                }
            }

            if (complete) ans++;
        }

        return ans;
    }
}
