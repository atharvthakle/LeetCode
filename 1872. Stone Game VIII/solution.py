class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        prefix = stones[0]
        for i in range(1, len(stones)):
            prefix += stones[i]
            stones[i] = prefix

        best = stones[-1]

        for i in range(len(stones) - 2, 0, -1):
            best = max(best, stones[i] - best)

        return best
