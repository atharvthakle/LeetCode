from typing import List

class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        
        robots = sorted(
            [(positions[i], healths[i], directions[i], i) for i in range(n)]
        )

        stack = []  # holds indices in robots list
        alive = [True] * n

        for i in range(n):
            pos, health, dirc, idx = robots[i]

            if dirc == 'R':
                stack.append(i)
            else:
                # L robot → check collisions
                while stack:
                    j = stack[-1]
                    if robots[j][1] < health:
                        # R dies
                        alive[j] = False
                        stack.pop()
                        health -= 1
                    elif robots[j][1] == health:
                        # both die
                        alive[j] = False
                        alive[i] = False
                        stack.pop()
                        break
                    else:
                        # L dies
                        alive[i] = False
                        robots[j] = (robots[j][0], robots[j][1] - 1, robots[j][2], robots[j][3])
                        break
                else:
                    # no R → survives
                    robots[i] = (pos, health, dirc, idx)

        # collect survivors
        result = []
        final_health = {}

        for i in range(n):
            if alive[i]:
                final_health[robots[i][3]] = robots[i][1]

        for i in range(n):
            if i in final_health:
                result.append(final_health[i])

        return result
