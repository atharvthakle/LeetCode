from math import gcd
from typing import List

class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        stack = []
        
        for num in nums:
            # Keep merging with stack top while GCD > 1
            while stack and gcd(stack[-1], num) > 1:
                num = (stack[-1] * num) // gcd(stack[-1], num)
                stack.pop()
            stack.append(num)
        
        return stack
