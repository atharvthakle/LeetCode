class Solution:
    def countOfAtoms(self, formula: str) -> str:
        from collections import defaultdict

        stack = [defaultdict(int)]  # Stack to manage scopes of parentheses
        i, n = 0, len(formula)

        while i < n:
            if formula[i] == '(':
                stack.append(defaultdict(int))  # New scope
                i += 1

            elif formula[i] == ')':
                i += 1
                # Parse multiplier after closing parenthesis
                start = i
                while i < n and formula[i].isdigit():
                    i += 1
                multiplier = int(formula[start:i] or 1)

                # Pop top map and apply multiplier
                top = stack.pop()
                for atom, count in top.items():
                    stack[-1][atom] += count * multiplier

            else:
                # Parse element name (e.g., "H", "He", "Mg")
                start = i
                i += 1  # first char is uppercase
                while i < n and formula[i].islower():
                    i += 1
                element = formula[start:i]

                # Parse number (if any)
                start = i
                while i < n and formula[i].isdigit():
                    i += 1
                count = int(formula[start:i] or 1)

                stack[-1][element] += count

        # Final counts are in stack[0]
        result = ""
        for atom in sorted(stack[-1]):
            count = stack[-1][atom]
            result += atom + (str(count) if count > 1 else "")
        return result
