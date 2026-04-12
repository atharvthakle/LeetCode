class Solution:
    def minimumDistance(self, word: str) -> int:
        
        # helper: distance between two chars
        def dist(a, b):
            if a == -1:
                return 0
            x1, y1 = divmod(a, 6)
            x2, y2 = divmod(b, 6)
            return abs(x1 - x2) + abs(y1 - y2)
        
        n = len(word)
        
        # dp[other finger position] = min cost
        dp = { -1: 0 }  # -1 means unused finger
        
        for i in range(n):
            curr = ord(word[i]) - ord('A')
            new_dp = {}
            
            for other, cost in dp.items():
                # Option 1: use same finger (move from prev char)
                if i > 0:
                    prev = ord(word[i-1]) - ord('A')
                    cost1 = cost + dist(prev, curr)
                else:
                    cost1 = cost
                
                new_dp[other] = min(new_dp.get(other, float('inf')), cost1)
                
                # Option 2: use other finger
                cost2 = cost + dist(other, curr)
                prev = ord(word[i-1]) - ord('A') if i > 0 else curr
                new_dp[prev] = min(new_dp.get(prev, float('inf')), cost2)
            
            dp = new_dp
        
        return min(dp.values())
