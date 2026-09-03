import java.util.*;

class Solution {
    public int minMoves(String[] classroom, int energy) {
        int m = classroom.length;
        int n = classroom[0].length();

        int start = -1;
        int litterCount = 0;
        int[][] litterId = new int[m][n];

        for (int i = 0; i < m; i++) {
            Arrays.fill(litterId[i], -1);
            for (int j = 0; j < n; j++) {
                char ch = classroom[i].charAt(j);

                if (ch == 'S') {
                    start = i * n + j;
                } else if (ch == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        if (litterCount == 0) return 0;

        int fullMask = (1 << litterCount) - 1;

        // best[mask][position] = maximum remaining energy seen
        int[][] best = new int[1 << litterCount][m * n];
        for (int[] row : best) {
            Arrays.fill(row, -1);
        }

        Queue<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[]{start, 0, energy, 0});
        best[0][start] = energy;

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!queue.isEmpty()) {
            int[] state = queue.poll();

            int pos = state[0];
            int mask = state[1];
            int remaining = state[2];
            int moves = state[3];

            int r = pos / n;
            int c = pos % n;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                char cell = classroom[nr].charAt(nc);
                if (cell == 'X') continue;

                // Need energy to make a move
                if (remaining == 0) continue;

                int newEnergy = remaining - 1;
                int newMask = mask;

                if (cell == 'L') {
                    newMask |= 1 << litterId[nr][nc];
                }

                // Reset energy upon reaching R
                if (cell == 'R') {
                    newEnergy = energy;
                }

                int newPos = nr * n + nc;

                if (newMask == fullMask) {
                    return moves + 1;
                }

                // A state with more remaining energy dominates one
                // with the same position and collected litter.
                if (newEnergy > best[newMask][newPos]) {
                    best[newMask][newPos] = newEnergy;
                    queue.offer(new int[]{
                        newPos, newMask, newEnergy, moves + 1
                    });
                }
            }
        }

        return -1;
    }
}
