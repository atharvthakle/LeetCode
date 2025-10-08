class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []
        
        def backtrack(index, path, calc, tail):
            # Base case: reached the end of num
            if index == len(num):
                if calc == target:
                    res.append(path)
                return
            
            # Try all possible splits
            for i in range(index, len(num)):
                # Skip numbers with leading zero
                if i != index and num[index] == '0':
                    break
                    
                curr_str = num[index:i+1]
                curr = int(curr_str)
                
                if index == 0:
                    # First number — start the expression
                    backtrack(i + 1, curr_str, curr, curr)
                else:
                    # Add '+'
                    backtrack(i + 1, path + '+' + curr_str, calc + curr, curr)
                    # Add '-'
                    backtrack(i + 1, path + '-' + curr_str, calc - curr, -curr)
                    # Add '*'
                    backtrack(i + 1, path + '*' + curr_str, calc - tail + tail * curr, tail * curr)
        
        backtrack(0, "", 0, 0)
        return res
