from collections import Counter
import functools

class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        
        def shrink(s):
            i = 0
            while i < len(s):
                j = i
                while j < len(s) and s[j] == s[i]:
                    j += 1
                if j - i >= 3:
                    return shrink(s[:i] + s[j:])
                i = j
            return s
        
        hand_count = Counter(hand)
        
        @functools.lru_cache(None)
        def dfs(curr_board, hand_key):
            if not curr_board:
                return 0
            
            hand_map = dict(zip("RYBGW", hand_key))
            res = float('inf')
            
            for i in range(len(curr_board) + 1):
                for c in "RYBGW":
                    if hand_map[c] == 0:
                        continue
                    
                    # pruning condition
                    if i > 0 and curr_board[i-1] == c:
                        valid = True
                    elif i < len(curr_board) and curr_board[i] == c:
                        valid = True
                    elif i > 0 and i < len(curr_board) and curr_board[i-1] == curr_board[i]:
                        valid = True
                    else:
                        valid = False
                    
                    if not valid:
                        continue
                    
                    # use ball
                    hand_map[c] -= 1
                    new_board = shrink(curr_board[:i] + c + curr_board[i:])
                    new_hand_key = tuple(hand_map[x] for x in "RYBGW")
                    
                    temp = dfs(new_board, new_hand_key)
                    if temp != -1:
                        res = min(res, temp + 1)
                    
                    # backtrack
                    hand_map[c] += 1
            
            return res if res != float('inf') else -1
        
        return dfs(board, tuple(hand_count[c] for c in "RYBGW"))
