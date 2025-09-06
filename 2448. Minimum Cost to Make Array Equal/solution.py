class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:
        # Combine nums and cost and sort by nums
        paired = sorted(zip(nums, cost))
        
        total_cost = sum(cost)
        half_cost = total_cost / 2
        
        # Find the weighted median
        cumulative = 0
        for num, c in paired:
            cumulative += c
            if cumulative >= half_cost:
                target = num
                break
        
        # Compute total cost to make all elements equal to target
        min_total = sum(abs(num - target) * c for num, c in zip(nums, cost))
        return min_total
