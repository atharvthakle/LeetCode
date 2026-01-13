using System;
using System.Collections.Generic;

public class Solution {
    public bool IsRectangleCover(int[][] rectangles) {
        long areaSum = 0;
        
        int minX = int.MaxValue;
        int minY = int.MaxValue;
        int maxX = int.MinValue;
        int maxY = int.MinValue;
        
        HashSet<string> corners = new HashSet<string>();
        
        foreach (var r in rectangles) {
            int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            
            // Update bounding rectangle
            minX = Math.Min(minX, x1);
            minY = Math.Min(minY, y1);
            maxX = Math.Max(maxX, x2);
            maxY = Math.Max(maxY, y2);
            
            // Add area
            areaSum += (long)(x2 - x1) * (y2 - y1);
            
            // Process 4 corners
            string[] pts = {
                x1 + "," + y1,
                x1 + "," + y2,
                x2 + "," + y1,
                x2 + "," + y2
            };
            
            foreach (string p in pts) {
                if (!corners.Add(p)) 
                    corners.Remove(p);
            }
        }
        
        // Area of bounding rectangle
        long boundingArea = (long)(maxX - minX) * (maxY - minY);
        if (areaSum != boundingArea) return false;
        
        // Must have exactly 4 corners left
        if (corners.Count != 4) return false;
        
        // Must be the 4 bounding corners
        return corners.Contains(minX + "," + minY) &&
               corners.Contains(minX + "," + maxY) &&
               corners.Contains(maxX + "," + minY) &&
               corners.Contains(maxX + "," + maxY);
    }
}
