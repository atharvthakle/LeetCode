from collections import Counter
from functools import reduce
from operator import mul

class Solution:
    def countKSubsequencesWithMaxBeauty(self, s: str, k: int) -> int:
        MOD = 10**9 + 7
        freq = list(Counter(s).values())
        freq.sort(reverse=True)

        if k > len(freq):
            return 0

        # Get top k frequencies
        top_k = freq[:k]
        threshold = top_k[-1]

        # Count how many frequencies equal threshold
        total_threshold = freq.count(threshold)
        chosen_threshold = top_k.count(threshold)

        # Number of ways = C(total_threshold, chosen_threshold) *
        # product of frequencies of top k characters
        from math import comb

        ways = comb(total_threshold, chosen_threshold) % MOD
        product = 1
        for f in top_k:
            product = (product * f) % MOD

        return (ways * product) % MOD
