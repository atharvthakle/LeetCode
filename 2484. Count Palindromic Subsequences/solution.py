class Solution:
    def countPalindromes(self, s: str) -> int:
        MOD = 10**9 + 7
        n = len(s)
        if n < 5:
            return 0

        digits = [ord(ch) - 48 for ch in s]  # 0..9

        # pairs_suffix[pos] is a flattened 10x10 array (index = a*10 + b)
        # counting number of ordered pairs (a,b) with left index >= pos < right index in suffix
        pairs_suffix = [[0]*100 for _ in range(n+1)]
        cnt = [0]*10  # counts of single digits seen so far while scanning from right

        # Build pairs for suffixes by scanning from right to left
        for pos in range(n-1, -1, -1):
            val = digits[pos]
            # start by copying next suffix counts
            arr = pairs_suffix[pos+1].copy()
            # every existing digit d to the right creates a pair (val, d) with left at pos
            base = val * 10
            for d in range(10):
                arr[base + d] += cnt[d]
            pairs_suffix[pos] = arr
            cnt[val] += 1

        # Sweep left to right: maintain left_counts and left_pairs (flattened)
        left_count = [0]*10
        left_pairs = [0]*100
        ans = 0

        for i in range(n):
            # right pairs should be pairs in suffix starting at i+1
            right_pairs = pairs_suffix[i+1]

            # number of palindromes centered at i is sum_{a,b} left_pairs[a*10+b] * right_pairs[b*10+a]
            total = 0
            for a in range(10):
                a10 = a*10
                for b in range(10):
                    total += left_pairs[a10 + b] * right_pairs[b*10 + a]
            ans = (ans + total) % MOD

            # now incorporate s[i] into left side for future centers:
            # for any d, new left pair (d, s[i]) increases by left_count[d]
            mid = digits[i]
            for d in range(10):
                left_pairs[d*10 + mid] += left_count[d]
            left_count[mid] += 1

        return ans % MOD
