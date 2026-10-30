import java.util.*;

class Solution {
    public int shortestPath(int n, int[][] edges, String labels, int k) {
        List<int[]>[] graph = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] e : edges) {
            graph[e[0]].add(new int[]{e[1], e[2]});
        }

        int states = k + 1;
        long[] dist = new long[n * states];
        Arrays.fill(dist, Long.MAX_VALUE);

        PriorityQueue<long[]> pq = new PriorityQueue<>(
            Comparator.comparingLong(a -> a[0])
        );

        dist[1] = 0;
        pq.offer(new long[]{0, 0, 1});

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();

            long d = curr[0];
            int u = (int) curr[1];
            int run = (int) curr[2];

            int state = u * states + run;

            if (d != dist[state]) continue;

            if (u == n - 1) return (int) d;

            for (int[] edge : graph[u]) {
                int v = edge[0];
                int w = edge[1];

                int newRun = labels.charAt(u) == labels.charAt(v)
                    ? run + 1 : 1;

                if (newRun > k) continue;

                int nextState = v * states + newRun;
                long newDist = d + w;

                if (newDist < dist[nextState]) {
                    dist[nextState] = newDist;
                    pq.offer(new long[]{newDist, v, newRun});
                }
            }
        }

        return -1;
    }
}
