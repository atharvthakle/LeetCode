public class Solution {
    public int CountCoveredBuildings(int n, int[][] buildings) {
        // Group buildings by row and column
        var rowToCols = new Dictionary<int, List<int>>();
        var colToRows = new Dictionary<int, List<int>>();

        foreach (var b in buildings) {
            int x = b[0], y = b[1];

            if (!rowToCols.ContainsKey(x)) rowToCols[x] = new List<int>();
            if (!colToRows.ContainsKey(y)) colToRows[y] = new List<int>();

            rowToCols[x].Add(y);
            colToRows[y].Add(x);
        }

        // Sort the coordinate lists
        foreach (var key in rowToCols.Keys.ToList())
            rowToCols[key].Sort();

        foreach (var key in colToRows.Keys.ToList())
            colToRows[key].Sort();

        int covered = 0;

        // Helper binary search function
        bool ExistsLess(List<int> arr, int v) {
            int idx = arr.BinarySearch(v);
            return idx > 0;
        }

        bool ExistsGreater(List<int> arr, int v) {
            int idx = arr.BinarySearch(v);
            return idx >= 0 && idx < arr.Count - 1;
        }

        // Check each building
        foreach (var b in buildings) {
            int x = b[0], y = b[1];

            var cols = rowToCols[x];
            var rows = colToRows[y];

            bool hasLeft = ExistsLess(cols, y);
            bool hasRight = ExistsGreater(cols, y);
            bool hasUp = ExistsLess(rows, x);
            bool hasDown = ExistsGreater(rows, x);

            if (hasLeft && hasRight && hasUp && hasDown)
                covered++;
        }

        return covered;
    }
}
