import java.util.*;

class Solution {

    int[][] dirs = {{0,1},{0,-1},{1,0},{-1,0}}; // R L D U

    // street type → allowed directions
    Map<Integer, int[][]> map = new HashMap<>();

    public boolean hasValidPath(int[][] grid) {
        int m = grid.length, n = grid[0].length;

        // define allowed directions
        map.put(1, new int[][]{{0,-1},{0,1}});
        map.put(2, new int[][]{{-1,0},{1,0}});
        map.put(3, new int[][]{{0,-1},{1,0}});
        map.put(4, new int[][]{{0,1},{1,0}});
        map.put(5, new int[][]{{0,-1},{-1,0}});
        map.put(6, new int[][]{{0,1},{-1,0}});

        boolean[][] visited = new boolean[m][n];
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0,0});
        visited[0][0] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];

            if (x == m-1 && y == n-1) return true;

            for (int[] d : map.get(grid[x][y])) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
                    continue;

                // check if neighbor connects back
                for (int[] back : map.get(grid[nx][ny])) {
                    if (nx + back[0] == x && ny + back[1] == y) {
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx, ny});
                        break;
                    }
                }
            }
        }

        return false;
    }
}
