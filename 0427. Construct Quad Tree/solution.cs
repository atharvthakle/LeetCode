public class Solution {
    public Node Construct(int[][] grid) {
        int n = grid.Length;
        return Build(grid, 0, 0, n);
    }

    private Node Build(int[][] grid, int row, int col, int size) {
        // Check if all cells in this square are the same
        bool isSame = true;
        int firstVal = grid[row][col];

        for (int i = row; i < row + size && isSame; i++) {
            for (int j = col; j < col + size; j++) {
                if (grid[i][j] != firstVal) {
                    isSame = false;
                    break;
                }
            }
        }

        // If uniform → leaf node
        if (isSame) {
            return new Node(firstVal == 1, true);
        }

        // Otherwise split into four quadrants
        int half = size / 2;

        Node topLeft = Build(grid, row, col, half);
        Node topRight = Build(grid, row, col + half, half);
        Node bottomLeft = Build(grid, row + half, col, half);
        Node bottomRight = Build(grid, row + half, col + half, half);

        // Internal node (val can be arbitrary when isLeaf = false)
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
}
