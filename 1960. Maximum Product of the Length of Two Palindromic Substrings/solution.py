class Solution:
    def maxProduct(self, s: str) -> int:
        n = len(s)
      
        # Step 1: Use Manacher's algorithm to find all odd-length palindromes
        # half_lengths[i] represents half-length of palindrome centered at i
        half_lengths = [0] * n
        center = right_boundary = 0
      
        for i in range(n):
            # Use previously computed palindromes to initialize current position
            if i < right_boundary:
                mirror_idx = 2 * center - i
                half_lengths[i] = min(right_boundary - i, half_lengths[mirror_idx])
          
            # Expand palindrome centered at i
            while (0 <= i - 1 - half_lengths[i] and 
                   i + 1 + half_lengths[i] < n and 
                   s[i - 1 - half_lengths[i]] == s[i + 1 + half_lengths[i]]):
                half_lengths[i] += 1
          
            # Update center and right boundary if current palindrome extends further
            if right_boundary < i + half_lengths[i]:
                center = i
                right_boundary = i + half_lengths[i]
      
        # Step 2: Build prefix and suffix arrays
        # prefix[i] = length of longest palindrome ending at or before index i
        # suffix[i] = length of longest palindrome starting at or after index i
        prefix = [0] * n
        suffix = [0] * n
      
        # Initialize with palindromes at their exact boundaries
        for i in range(n):
            right_end = i + half_lengths[i]
            left_start = i - half_lengths[i]
            palindrome_length = 2 * half_lengths[i] + 1
          
            prefix[right_end] = max(prefix[right_end], palindrome_length)
            suffix[left_start] = max(suffix[left_start], palindrome_length)
      
        # Step 3: Propagate palindrome lengths inward (shrinking by 2 each time)
        # A palindrome of length L contains palindromes of length L-2, L-4, etc.
        for i in range(1, n):
            # Process from right to left for prefix array
            idx = n - 1 - i  # Using ~i equivalent: ~i = -i - 1
            prefix[idx] = max(prefix[idx], prefix[idx + 1] - 2)
            # Process from left to right for suffix array
            suffix[i] = max(suffix[i], suffix[i - 1] - 2)
      
        # Step 4: Calculate cumulative maximum for prefix and suffix arrays
        for i in range(1, n):
            # prefix[i] should be max of all palindromes ending at or before i
            prefix[i] = max(prefix[i - 1], prefix[i])
            # suffix[i] should be max of all palindromes starting at or after i
            idx = n - 1 - i  # Using ~i equivalent
            suffix[idx] = max(suffix[idx], suffix[idx + 1])
      
        # Step 5: Find maximum product by trying all split points
        max_product = 0
        for split_point in range(1, n):
            # Product of best palindrome before split and best palindrome after split
            product = prefix[split_point - 1] * suffix[split_point]
            max_product = max(max_product, product)
      
        return max_product
