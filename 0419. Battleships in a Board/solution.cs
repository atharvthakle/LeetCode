public class Solution {
    public int CountBattleships(char[][] board) {
        int m = board.Length;
        int n = board[0].Length;
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'X') continue;

                // check top cell
                if (i > 0 && board[i - 1][j] == 'X') continue;

                // check left cell
                if (j > 0 && board[i][j - 1] == 'X') continue;

                // this is the start of a battleship
                count++;
            }
        }

        return count;
    }
}
