class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        # Helper to factorize t into prime counts of (2, 3, 5, 7)
        def get_prime_count(val):
            cnt = {2: 0, 3: 0, 5: 0, 7: 0}
            for p in (2, 3, 5, 7):
                while val % p == 0:
                    val //= p
                    cnt[p] += 1
            return cnt, val == 1

        prime_cnt, ok = get_prime_count(t)
        if not ok:
            return "-1"

        factor_counts = {
            0: {2: 0, 3: 0, 5: 0, 7: 0},
            1: {2: 0, 3: 0, 5: 0, 7: 0},
            2: {2: 1, 3: 0, 5: 0, 7: 0},
            3: {2: 0, 3: 1, 5: 0, 7: 0},
            4: {2: 2, 3: 0, 5: 0, 7: 0},
            5: {2: 0, 3: 0, 5: 1, 7: 0},
            6: {2: 1, 3: 1, 5: 0, 7: 0},
            7: {2: 0, 3: 0, 5: 0, 7: 1},
            8: {2: 3, 3: 0, 5: 0, 7: 0},
            9: {2: 0, 3: 2, 5: 0, 7: 0},
        }

        def get_factor_count_from_counts(count):
            c2 = count.get(2, 0)
            c3 = count.get(3, 0)
            c5 = count.get(5, 0)
            c7 = count.get(7, 0)

            count8 = c2 // 3
            rem2 = c2 % 3
            count9 = c3 // 2
            rem3 = c3 % 2
            count4 = rem2 // 2
            rem2 %= 2

            count2 = rem2
            count3 = rem3
            count6 = 0
            if count2 == 1 and count3 == 1:
                count2 = 0
                count3 = 0
                count6 = 1
            if count3 == 1 and count4 == 1:
                count2 = 1
                count6 = 1
                count3 = 0
                count4 = 0

            res = {2: count2, 3: count3, 4: count4, 5: c5, 6: count6, 7: c7, 8: count8, 9: count9}
            return {k: v for k, v in res.items() if v > 0}

        def subtract_counts(a, b):
            res = a.copy()
            for k, v in b.items():
                res[k] = max(0, res.get(k, 0) - v)
            return res

        def sum_values(count):
            return sum(count.values())

        def construct(factor_map):
            res = []
            for d in (9, 8, 7, 6, 5, 4, 3, 2):
                if d in factor_map:
                    res.extend([str(d)] * factor_map[d])
            res.sort()
            return "".join(res)

        min_factor_count = get_factor_count_from_counts(prime_cnt)
        if sum_values(min_factor_count) > len(num):
            return construct(min_factor_count)

        # Compute prefix prime counts of num
        prefix_prime_count = {2: 0, 3: 0, 5: 0, 7: 0}
        first_zero_idx = num.find('0')
        if first_zero_idx == -1:
            first_zero_idx = len(num)
            # Check if num itself is valid
            curr_pc = {2: 0, 3: 0, 5: 0, 7: 0}
            for ch in num:
                fc = factor_counts[int(ch)]
                for p in fc:
                    curr_pc[p] += fc[p]
            if all(curr_pc[p] >= prime_cnt[p] for p in prime_cnt):
                return num

        for i, ch in enumerate(num):
            fc = factor_counts[int(ch)]
            for p in fc:
                prefix_prime_count[p] += fc[p]

        # Scan from right to left
        for i in range(len(num) - 1, -1, -1):
            d = int(num[i])
            fc = factor_counts[d]
            for p in fc:
                prefix_prime_count[p] -= fc[p]

            space_after = len(num) - 1 - i
            if i > first_zero_idx:
                continue

            for bigger_dig in range(d + 1, 10):
                rem_prime = subtract_counts(prime_cnt, prefix_prime_count)
                fc_bigger = factor_counts[bigger_dig]
                rem_prime = subtract_counts(rem_prime, fc_bigger)

                factors_needed = get_factor_count_from_counts(rem_prime)
                if sum_values(factors_needed) <= space_after:
                    extra_ones = space_after - sum_values(factors_needed)
                    rest_str = "1" * extra_ones + construct(factors_needed)
                    return num[:i] + str(bigger_dig) + rest_str

        # If length can be increased
        extended_len = len(num) + 1
        factors_needed = get_factor_count_from_counts(prime_cnt)
        extra_ones = extended_len - sum_values(factors_needed)
        return "1" * max(0, extra_ones) + construct(factors_needed)
