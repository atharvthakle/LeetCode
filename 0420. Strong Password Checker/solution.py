class Solution:
    def strongPasswordChecker(self, password: str) -> int:
        n = len(password)

        # Check missing character types
        has_lower = any(c.islower() for c in password)
        has_upper = any(c.isupper() for c in password)
        has_digit = any(c.isdigit() for c in password)

        missing_types = 3 - (has_lower + has_upper + has_digit)

        # Find repeating groups
        repeats = []
        i = 0
        while i < n:
            j = i
            while j < n and password[j] == password[i]:
                j += 1
            length = j - i
            if length >= 3:
                repeats.append(length)
            i = j

        # Case 1: length < 6
        if n < 6:
            return max(missing_types, 6 - n)

        # Count replacements needed without deletions
        replace = sum(length // 3 for length in repeats)

        # Case 2: length <= 20
        if n <= 20:
            return max(missing_types, replace)

        # Case 3: length > 20
        delete_required = n - 20
        remaining_delete = delete_required

        # Sort repeats by mod 3 to optimize deletions
        repeats.sort(key=lambda x: x % 3)

        for idx in range(len(repeats)):
            if remaining_delete <= 0:
                break
            length = repeats[idx]

            if length < 3:
                continue

            mod = length % 3
            # deletions needed to reduce one replacement
            need = mod + 1

            if remaining_delete >= need:
                repeats[idx] -= need
                remaining_delete -= need
            else:
                repeats[idx] -= remaining_delete
                remaining_delete = 0

        # If deletions still remain, remove in chunks of 3
        for idx in range(len(repeats)):
            if remaining_delete <= 0:
                break
            length = repeats[idx]
            if length < 3:
                continue

            need = length - 2
            remove = min(remaining_delete, need)
            repeats[idx] -= remove
            remaining_delete -= remove

        # Recompute replacements after deletions
        replace = sum(length // 3 for length in repeats)

        return delete_required + max(missing_types, replace)
