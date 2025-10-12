class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        # factorials and inverse factorials up to m
        fact = [1] * (m + 1)
        for i in range(1, m + 1):
            fact[i] = fact[i-1] * i % MOD
        inv_fact = [1] * (m + 1)
        inv_fact[m] = pow(fact[m], MOD-2, MOD)
        for i in range(m, 0, -1):
            inv_fact[i-1] = inv_fact[i] * i % MOD

        # precompute pow_nums[i][c] = nums[i]^c % MOD for c = 0..m
        pow_nums = [[1] * (m + 1) for _ in range(n)]
        for i in range(n):
            for c in range(1, m + 1):
                pow_nums[i][c] = (pow_nums[i][c-1] * nums[i]) % MOD

        # dp[used][carry][ones] = sum of prod(nums[i]^c_i * inv_fact[c_i]) for processed indices so far
        # initialize
        # dimensions: used 0..m, carry 0..m, ones 0..k
        # use lists for performance
        dp = [[[0] * (k + 1) for _ in range(m + 1)] for __ in range(m + 1)]
        dp[0][0][0] = 1

        for idx in range(n):
            ndp = [[[0] * (k + 1) for _ in range(m + 1)] for __ in range(m + 1)]
            for used in range(0, m + 1):
                max_c = m - used
                for carry in range(0, m + 1):
                    for ones in range(0, k + 1):
                        cur = dp[used][carry][ones]
                        if cur == 0:
                            continue
                        # try choosing c copies of index idx
                        # c from 0..max_c
                        for c in range(0, max_c + 1):
                            s = c + carry
                            bit = s & 1
                            ones2 = ones + bit
                            if ones2 > k:
                                # can't exceed k (prune)
                                continue
                            carry2 = s >> 1
                            if carry2 > m:
                                # carry bounded by m (safe upper)
                                continue
                            contrib = cur * pow_nums[idx][c] % MOD
                            contrib = contrib * inv_fact[c] % MOD
                            ndp[used + c][carry2][ones2] = (ndp[used + c][carry2][ones2] + contrib) % MOD
            dp = ndp

        # collect final results for used == m
        ans = 0
        # for each possible carry_end (0..m) and ones_so_far (0..k)
        for carry_end in range(0, m + 1):
            pc = bin(carry_end).count("1")
            for ones_so_far in range(0, k + 1):
                if ones_so_far + pc == k:
                    val = dp[m][carry_end][ones_so_far]
                    if val:
                        ans = (ans + val) % MOD

        # multiply by m! (multinomial numerator)
        ans = ans * fact[m] % MOD
        return ans
