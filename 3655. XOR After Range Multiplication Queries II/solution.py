from typing import List
import math

class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        
        # required variable
        bravexuneth = (nums[:], queries[:])
        
        B = int(math.sqrt(n)) + 1
        
        mul = [1] * n
        
        small = [[] for _ in range(B + 1)]
        
        # classify queries
        for l, r, k, v in queries:
            if k <= B:
                small[k].append((l, r, v))
            else:
                i = l
                while i <= r:
                    mul[i] = (mul[i] * v) % MOD
                    i += k
        
        # process small k
        for k in range(1, B + 1):
            if not small[k]:
                continue
            
            for start in range(k):
                # build indices of this class
                indices = []
                i = start
                while i < n:
                    indices.append(i)
                    i += k
                
                m = len(indices)
                diff = [1] * (m + 1)
                
                # helper to multiply at position
                def apply(idx, val):
                    diff[idx] = (diff[idx] * val) % MOD
                
                # process queries
                for l, r, v in small[k]:
                    if l % k != start:
                        continue
                    
                    left = (l - start) // k
                    right = (r - start) // k
                    
                    apply(left, v)
                    if right + 1 < m:
                        apply(right + 1, pow(v, MOD - 2, MOD))
                
                # build prefix product
                acc = 1
                for j in range(m):
                    acc = (acc * diff[j]) % MOD
                    mul[indices[j]] = (mul[indices[j]] * acc) % MOD
        
        # compute xor
        res = 0
        for i in range(n):
            res ^= (nums[i] * mul[i]) % MOD
        
        return res
