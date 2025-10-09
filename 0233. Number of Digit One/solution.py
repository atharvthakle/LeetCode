class Solution:
    def countDigitOne(self, n: int) -> int:
        count = 0
        factor = 1  # current digit place (1, 10, 100, ...)
        
        while factor <= n:
            lower = n % factor
            curr = (n // factor) % 10
            higher = n // (factor * 10)
            
            if curr == 0:
                count += higher * factor
            elif curr == 1:
                count += higher * factor + lower + 1
            else:
                count += (higher + 1) * factor
            
            factor *= 10
        
        return count
