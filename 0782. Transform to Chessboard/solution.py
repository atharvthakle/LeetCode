from typing import List

class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        n = len(board)

        # Step 1: validity check
        for i in range(n):
            for j in range(n):
                if board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]:
                    return -1

        # Step 2: count ones and misplaced rows/cols
        rowSum = sum(board[0])          # number of 1s in first row
        colSum = sum(board[i][0] for i in range(n))  # number of 1s in first column

        rowSwap = 0
        colSwap = 0

        for i in range(n):
            # how many rows differ from pattern 0,1,0,1...
            if board[i][0] == i % 2:
                rowSwap += 1
            if board[0][i] == i % 2:
                colSwap += 1

        # Step 3: check counts valid
        if not (n//2 <= rowSum <= (n+1)//2):
            return -1
        if not (n//2 <= colSum <= (n+1)//2):
            return -1

        # Step 4: compute minimal swaps
        if n % 2:
            # odd case: only one valid pattern
            if rowSwap % 2:
                rowSwap = n - rowSwap
            if colSwap % 2:
                colSwap = n - colSwap
        else:
            # even case: take minimum
            rowSwap = min(rowSwap, n - rowSwap)
            colSwap = min(colSwap, n - colSwap)

        return (rowSwap + colSwap) // 2
