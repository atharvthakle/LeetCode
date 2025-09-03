class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        empties = []

        # Initialize sets with existing numbers
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    empties.append((i, j))
                else:
                    num = board[i][j]
                    rows[i].add(num)
                    cols[j].add(num)
                    boxes[(i // 3) * 3 + (j // 3)].add(num)

        def backtrack(idx=0):
            if idx == len(empties):
                return True  # solved

            r, c = empties[idx]
            b = (r // 3) * 3 + (c // 3)

            for ch in map(str, range(1, 10)):
                if ch not in rows[r] and ch not in cols[c] and ch not in boxes[b]:
                    board[r][c] = ch
                    rows[r].add(ch)
                    cols[c].add(ch)
                    boxes[b].add(ch)

                    if backtrack(idx + 1):
                        return True

                    # undo
                    board[r][c] = "."
                    rows[r].remove(ch)
                    cols[c].remove(ch)
                    boxes[b].remove(ch)

            return False

        backtrack()
