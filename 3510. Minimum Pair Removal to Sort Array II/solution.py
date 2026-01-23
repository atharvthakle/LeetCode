class Solution:
    def minimumPairRemoval(self, nums):
        n = len(nums)
        if n <= 1:
            return 0
        
        # Doubly linked list structure
        prev = list(range(-1, n-1))
        next = list(range(1, n+1))
        alive = [True]*n
        val = nums[:]
        
        import heapq
        heap = []
        
        # Build initial heap of pairs
        for i in range(n-1):
            heapq.heappush(heap, (val[i] + val[i+1], i))
        
        # Count initial violations
        violations = 0
        for i in range(n-1):
            if val[i] > val[i+1]:
                violations += 1
        
        ops = 0
        
        while violations > 0:
            s, i = heapq.heappop(heap)
            j = next[i]
            
            # Validate pair still exists
            if j >= n or not alive[i] or not alive[j]:
                continue
            if val[i] + val[j] != s:
                continue
            
            # Before merge: remove old violation contributions
            pi = prev[i]
            nj = next[j]
            
            if pi != -1 and val[pi] > val[i]:
                violations -= 1
            if val[i] > val[j]:
                violations -= 1
            if nj < n and val[j] > val[nj]:
                violations -= 1
            
            # Merge j into i
            val[i] += val[j]
            alive[j] = False
            next[i] = nj
            if nj < n:
                prev[nj] = i
            
            # After merge: add new violation contributions
            if pi != -1 and val[pi] > val[i]:
                violations += 1
            if nj < n and val[i] > val[nj]:
                violations += 1
            
            # Push new adjacent pairs involving i
            if pi != -1:
                heapq.heappush(heap, (val[pi] + val[i], pi))
            if nj < n:
                heapq.heappush(heap, (val[i] + val[nj], i))
            
            ops += 1
        
        return ops
