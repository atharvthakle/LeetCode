using System;
using System.Collections.Generic;

public class Solution {
    public int RobotSim(int[] commands, int[][] obstacles) {
        // Directions: N, E, S, W
        int[][] dirs = new int[][] {
            new int[]{0, 1},
            new int[]{1, 0},
            new int[]{0, -1},
            new int[]{-1, 0}
        };

        int dir = 0; // start facing North
        int x = 0, y = 0;
        int maxDist = 0;

        // Store obstacles
        HashSet<string> set = new HashSet<string>();
        foreach (var obs in obstacles) {
            set.Add(obs[0] + "," + obs[1]);
        }

        foreach (int cmd in commands) {
            if (cmd == -1) {
                // turn right
                dir = (dir + 1) % 4;
            } 
            else if (cmd == -2) {
                // turn left
                dir = (dir + 3) % 4;
            } 
            else {
                // move step by step
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dirs[dir][0];
                    int ny = y + dirs[dir][1];

                    if (set.Contains(nx + "," + ny)) {
                        break; // obstacle hit
                    }

                    x = nx;
                    y = ny;

                    maxDist = Math.Max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
}
