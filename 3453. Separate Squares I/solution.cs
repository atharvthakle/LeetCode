public class Solution {
    public double SeparateSquares(int[][] squares) {
        int n = squares.Length;
        
        double minY = double.MaxValue;
        double maxY = double.MinValue;
        double totalArea = 0;

        foreach (var s in squares) {
            double y = s[1];
            double l = s[2];
            minY = Math.Min(minY, y);
            maxY = Math.Max(maxY, y + l);
            totalArea += l * l;
        }

        double half = totalArea / 2.0;

        double lo = minY, hi = maxY;
        
        for (int iter = 0; iter < 60; iter++) { 
            double mid = (lo + hi) / 2.0;
            double below = AreaBelow(squares, mid);
            
            if (below < half)
                lo = mid;
            else
                hi = mid;
        }

        return lo;
    }

    private double AreaBelow(int[][] squares, double H) {
        double sum = 0.0;
        
        foreach (var s in squares) {
            double y = s[1];
            double l = s[2];
            double top = y + l;

            if (H <= y) {
                // contributes 0
            }
            else if (H >= top) {
                sum += l * l;
            }
            else {
                sum += (H - y) * l;
            }
        }
        
        return sum;
    }
}
