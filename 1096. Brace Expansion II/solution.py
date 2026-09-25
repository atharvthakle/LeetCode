class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        i = 0

        def parse_expr():
            nonlocal i
            res = parse_term()

            while i < len(expression) and expression[i] == ',':
                i += 1
                res |= parse_term()

            return res

        def parse_term():
            nonlocal i
            res = {""}

            while i < len(expression) and expression[i] not in "},":
                if expression[i] == '{':
                    i += 1
                    cur = parse_expr()
                    i += 1
                else:
                    cur = {expression[i]}
                    i += 1

                res = {a + b for a in res for b in cur}

            return res

        return sorted(parse_expr())
