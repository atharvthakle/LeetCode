class Solution:
    def totalNQueens(self, n: int) -> int:
        self.count = 0
        cols = set()
        diag1 = set()  # r - c
        diag2 = set()  # r + c

        def backtrack(r):
            if r == n:
                self.count += 1
                return
            for c in range(n):
                if c in cols or (r - c) in diag1 or (r + c) in diag2:
                    continue
                cols.add(c)
                diag1.add(r - c)
                diag2.add(r + c)
                backtrack(r + 1)
                cols.remove(c)
                diag1.remove(r - c)
                diag2.remove(r + c)

        backtrack(0)
        return self.count
