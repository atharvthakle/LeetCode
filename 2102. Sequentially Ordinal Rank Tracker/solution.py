from sortedcontainers import SortedList

class SORTracker:
    def __init__(self):
        # Initialize a sorted list to maintain locations in sorted order
        # Stores tuples of (-score, name) for automatic sorting
        self.sorted_locations = SortedList()
      
        # Track the current index for get() queries
        # Starts at -1 since it's incremented before each retrieval
        self.current_index = -1

    def add(self, name: str, score: int) -> None:
        """
        Add a new location with its score to the tracker.
      
        Args:
            name: The name of the location
            score: The score of the location
        """
        # Store as (-score, name) tuple for sorting:
        # - Negative score ensures higher scores come first
        # - Name as second element provides lexicographic tiebreaking
        self.sorted_locations.add((-score, name))

    def get(self) -> str:
        """
        Get the next best location based on previous queries.
      
        Returns:
            The name of the (i+1)-th best location where i is the number
            of times get() has been called previously.
        """
        # Increment index to get the next best location
        self.current_index += 1
      
        # Return the name (second element) of the tuple at current index
        return self.sorted_locations[self.current_index][1]


# Your SORTracker object will be instantiated and called as such:
# obj = SORTracker()
# obj.add(name, score)
# param_2 = obj.get()
