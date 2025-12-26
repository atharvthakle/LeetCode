from typing import List
import math
from functools import cmp_to_key

class Solution:
    def minDamage(self, power: int, damage: List[int], health: List[int]) -> int:
        n = len(damage)
        
        # Compute time needed to kill each enemy
        enemies = []
        for d, h in zip(damage, health):
            time = (h + power - 1) // power  # ceil division
            enemies.append((time, d))
        
        # Sort by time / damage (using cross multiplication)
        def cmp(a, b):
            # a = (time_a, damage_a), b = (time_b, damage_b)
            return a[0] * b[1] - b[0] * a[1]
        
        enemies.sort(key=cmp_to_key(cmp))
        
        total_damage = sum(damage)
        answer = 0
        
        for time, d in enemies:
            answer += total_damage * time
            total_damage -= d
        
        return answer
