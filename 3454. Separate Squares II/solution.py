class Solution:
    def separateSquares(self, squares):
        events = []  # (y, type, x1, x2)  type: +1 = add, -1 = remove
        
        for x, y, l in squares:
            events.append((y, 1, x, x + l))
            events.append((y + l, -1, x, x + l))
        
        events.sort()
        
        # Active x-intervals
        from bisect import insort, bisect_left
        
        active = []   # list of (x1, x2)
        
        def union_x_length():
            if not active:
                return 0
            intervals = sorted(active)
            total = 0
            cur_start, cur_end = intervals[0]
            for s, e in intervals[1:]:
                if s > cur_end:
                    total += cur_end - cur_start
                    cur_start, cur_end = s, e
                else:
                    cur_end = max(cur_end, e)
            total += cur_end - cur_start
            return total
        
        # First pass: compute total union area
        total_area = 0
        prev_y = events[0][0]
        
        for y, typ, x1, x2 in events:
            dy = y - prev_y
            if dy > 0:
                total_area += union_x_length() * dy
            if typ == 1:
                active.append((x1, x2))
            else:
                active.remove((x1, x2))
            prev_y = y
        
        half = total_area / 2.0
        
        # Second pass: find smallest y reaching half area
        active.clear()
        acc = 0
        prev_y = events[0][0]
        
        for y, typ, x1, x2 in events:
            dy = y - prev_y
            if dy > 0:
                width = union_x_length()
                area_here = width * dy
                if acc + area_here >= half:
                    # interpolate inside this segment
                    need = half - acc
                    return prev_y + need / width
                acc += area_here
            
            if typ == 1:
                active.append((x1, x2))
            else:
                active.remove((x1, x2))
            
            prev_y = y
        
        return prev_y
