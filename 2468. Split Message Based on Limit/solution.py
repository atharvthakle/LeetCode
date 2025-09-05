from typing import List

class Solution:
    def splitMessage(self, message: str, limit: int) -> List[str]:
        n = len(message)
        
        # If even the smallest suffix "<1/1>" doesn't fit
        if limit <= 5:  
            return []
        
        # Helper: compute total capacity for given b
        def capacity(b: int) -> int:
            digits_b = len(str(b))
            total = 0
            start = 1
            d = 1
            while start <= b:
                end = min(b, 10**d - 1)
                count = end - start + 1
                suffix_len = d + digits_b + 3  # digits(a) + digits(b) + 3
                if suffix_len >= limit:
                    return -1
                total += count * (limit - suffix_len)
                start *= 10
                d += 1
            return total
        
        # Find smallest b such that capacity(b) >= n
        b = 1
        while True:
            cap = capacity(b)
            if cap >= n:
                break
            b += 1
            if b > n:   # shouldn't happen, but safeguard
                return []
        
        # Now actually build parts
        res = []
        idx = 0
        for a in range(1, b + 1):
            suffix = f"<{a}/{b}>"
            size = limit - len(suffix)
            chunk = message[idx:idx + size]
            idx += size
            res.append(chunk + suffix)
            if idx >= n:
                break
        return res
