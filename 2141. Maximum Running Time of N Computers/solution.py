class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        batteries.sort()
        total = sum(batteries)

        # Binary search for maximum feasible runtime T
        left, right = 0, total // n

        def can_run(T):
            # Total available minutes if we run each battery at most T minutes
            available = 0
            for b in batteries:
                available += min(b, T)
            return available >= T * n

        while left < right:
            mid = (left + right + 1) // 2
            if can_run(mid):
                left = mid
            else:
                right = mid - 1

        return left
