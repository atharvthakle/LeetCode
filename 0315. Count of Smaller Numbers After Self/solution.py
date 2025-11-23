class Solution:
    def countSmaller(self, nums: list[int]) -> list[int]:
        # Coordinate compression to handle negative numbers
        sorted_unique = sorted(set(nums))
        rank = {num: i+1 for i, num in enumerate(sorted_unique)}  # 1-indexed for BIT
        
        # BIT / Fenwick Tree
        size = len(sorted_unique) + 1
        bit = [0] * (size)
        
        def update(i):
            while i < size:
                bit[i] += 1
                i += i & -i
        
        def query(i):
            res = 0
            while i > 0:
                res += bit[i]
                i -= i & -i
            return res
        
        res = []
        # traverse from right to left
        for num in reversed(nums):
            r = rank[num]
            # count of numbers smaller than current
            res.append(query(r - 1))
            # update BIT for current number
            update(r)
        
        return res[::-1]
