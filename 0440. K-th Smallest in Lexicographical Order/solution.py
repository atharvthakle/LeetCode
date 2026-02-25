class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        def count_steps(n, prefix, next_prefix):
            steps = 0
            while prefix <= n:
                steps += min(n + 1, next_prefix) - prefix
                prefix *= 10
                next_prefix *= 10
            return steps
        
        curr = 1
        k -= 1  # because we start at 1
        
        while k > 0:
            steps = count_steps(n, curr, curr + 1)
            
            if steps <= k:
                # Skip this subtree
                curr += 1
                k -= steps
            else:
                # Go deeper
                curr *= 10
                k -= 1
        
        return curr
