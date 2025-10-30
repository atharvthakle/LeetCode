class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        operations = target[0]  # start with the first element
        for i in range(1, len(target)):
            if target[i] > target[i - 1]:
                operations += target[i] - target[i - 1]
        return operations
