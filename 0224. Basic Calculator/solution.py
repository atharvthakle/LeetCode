class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        res = 0
        num = 0
        sign = 1  # current sign: +1 or -1
        i = 0
        
        while i < len(s):
            c = s[i]
            if c.isdigit():
                num = 0
                while i < len(s) and s[i].isdigit():
                    num = num * 10 + int(s[i])
                    i += 1
                res += sign * num
                num = 0
                continue  # skip incrementing i, already handled
            elif c == '+':
                sign = 1
            elif c == '-':
                sign = -1
            elif c == '(':
                # push current result and sign onto stack
                stack.append(res)
                stack.append(sign)
                res = 0
                sign = 1
            elif c == ')':
                # pop sign and previous result
                prev_sign = stack.pop()
                prev_res = stack.pop()
                res = prev_res + prev_sign * res
            # ignore spaces
            i += 1
        
        return res
