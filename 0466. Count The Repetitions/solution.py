class Solution:
    def getMaxRepetitions(self, s1: str, n1: int, s2: str, n2: int) -> int:
        if n1 == 0:
            return 0

        index2 = 0
        count1 = 0
        count2 = 0

        recall = {}

        while True:
            count1 += 1

            for c in s1:
                if c == s2[index2]:
                    index2 += 1
                    if index2 == len(s2):
                        count2 += 1
                        index2 = 0

            if count1 == n1:
                return count2 // n2

            if index2 in recall:
                prev_count1, prev_count2 = recall[index2]

                cycle_s1 = count1 - prev_count1
                cycle_s2 = count2 - prev_count2

                remaining = n1 - count1
                cycles = remaining // cycle_s1

                count1 += cycles * cycle_s1
                count2 += cycles * cycle_s2

                while count1 < n1:
                    count1 += 1
                    for c in s1:
                        if c == s2[index2]:
                            index2 += 1
                            if index2 == len(s2):
                                count2 += 1
                                index2 = 0

                return count2 // n2

            else:
                recall[index2] = (count1, count2)
