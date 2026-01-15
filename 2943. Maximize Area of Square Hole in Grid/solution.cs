public class Solution {
    public int MaximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        Array.Sort(hBars);
        Array.Sort(vBars);
        
        int maxH = LongestConsecutive(hBars);
        int maxV = LongestConsecutive(vBars);
        
        int height = maxH + 1;
        int width = maxV + 1;
        
        int side = Math.Min(height, width);
        return side * side;
    }
    
    private int LongestConsecutive(int[] arr) {
        int best = 1;
        int cur = 1;
        
        for (int i = 1; i < arr.Length; i++) {
            if (arr[i] == arr[i - 1] + 1) {
                cur++;
            } else {
                best = Math.Max(best, cur);
                cur = 1;
            }
        }
        best = Math.Max(best, cur);
        return best;
    }
}
