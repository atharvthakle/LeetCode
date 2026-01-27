class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)
        stoneIndex = {stones[i]: i for i in range(n)}
        
        # dp[i] = set of jump lengths that can land on stone i
        dp = [set() for _ in range(n)]
        dp[0].add(0)  # Starting at stone 0 with last jump 0
        
        for i in range(n):
            for jump in dp[i]:
                for step in (jump - 1, jump, jump + 1):
                    if step <= 0:
                        continue
                    nextPos = stones[i] + step
                    if nextPos in stoneIndex:
                        dp[stoneIndex[nextPos]].add(step)
        
        return len(dp[-1]) > 0
