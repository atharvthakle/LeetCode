class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        total_xor = 0
        for num in nums:
            total_xor ^= num
        return total_xor == 0 or len(nums) % 2 == 0
