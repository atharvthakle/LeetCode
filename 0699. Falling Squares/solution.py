class Solution:
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
        # Each element in 'intervals' will store (left, right, height)
        intervals = []
        result = []
        max_height = 0
        
        for left, side in positions:
            right = left + side
            base_height = 0  # height where the square will land
            
            # Check overlap with all existing intervals
            for l, r, h in intervals:
                # If overlapping, find the highest base height we can land on
                if not (r <= left or right <= l):
                    base_height = max(base_height, h)
            
            # New height after placing current square
            new_height = base_height + side
            intervals.append((left, right, new_height))
            max_height = max(max_height, new_height)
            result.append(max_height)
        
            # (Optional optimization: we can merge overlapping intervals of same height)
        
        return result
