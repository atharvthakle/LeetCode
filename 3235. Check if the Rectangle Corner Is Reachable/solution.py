class Solution:
    def canReachCorner(
        self, xCorner: int, yCorner: int, circles: List[List[int]]
    ) -> bool:
        """
        Determines if a path exists from (0, 0) to (xCorner, yCorner) 
        avoiding all given circles.
      
        Args:
            xCorner: x-coordinate of the target corner
            yCorner: y-coordinate of the target corner
            circles: List of circles, each defined as [center_x, center_y, radius]
      
        Returns:
            True if a path exists, False otherwise
        """
      
        def is_point_inside_circle(point_x: int, point_y: int, 
                                   circle_x: int, circle_y: int, radius: int) -> bool:
            """Check if a point is inside or on the boundary of a circle."""
            distance_squared = (point_x - circle_x) ** 2 + (point_y - circle_y) ** 2
            return distance_squared <= radius ** 2
      
        def intersects_left_or_top_boundary(circle_x: int, circle_y: int, radius: int) -> bool:
            """
            Check if circle intersects with left boundary (x=0) or top boundary (y=yCorner).
            These boundaries form the starting edges of the rectangle.
            """
            # Check intersection with left boundary (x=0) for y in [0, yCorner]
            intersects_left = abs(circle_x) <= radius and 0 <= circle_y <= yCorner
          
            # Check intersection with top boundary (y=yCorner) for x in [0, xCorner]
            intersects_top = abs(circle_y - yCorner) <= radius and 0 <= circle_x <= xCorner
          
            return intersects_left or intersects_top
      
        def intersects_right_or_bottom_boundary(circle_x: int, circle_y: int, radius: int) -> bool:
            """
            Check if circle intersects with right boundary (x=xCorner) or bottom boundary (y=0).
            These boundaries form the ending edges of the rectangle.
            """
            # Check intersection with right boundary (x=xCorner) for y in [0, yCorner]
            intersects_right = abs(circle_x - xCorner) <= radius and 0 <= circle_y <= yCorner
          
            # Check intersection with bottom boundary (y=0) for x in [0, xCorner]
            intersects_bottom = abs(circle_y) <= radius and 0 <= circle_x <= xCorner
          
            return intersects_right or intersects_bottom
      
        def depth_first_search(circle_index: int) -> bool:
            """
            DFS to check if there's a connected path of circles from left/top to right/bottom.
            Such a path would block movement from (0,0) to (xCorner, yCorner).
          
            Returns True if current circle leads to a blocking path.
            """
            current_x, current_y, current_radius = circles[circle_index]
          
            # If this circle touches right or bottom boundary, we found a blocking path
            if intersects_right_or_bottom_boundary(current_x, current_y, current_radius):
                return True
          
            # Mark current circle as visited
            visited[circle_index] = True
          
            # Check all other circles
            for next_index, (next_x, next_y, next_radius) in enumerate(circles):
                # Skip if already visited
                if visited[next_index]:
                    continue
              
                # Check if circles are connected (touching or overlapping)
                distance_squared = (current_x - next_x) ** 2 + (current_y - next_y) ** 2
                sum_radii_squared = (current_radius + next_radius) ** 2
              
                if distance_squared > sum_radii_squared:
                    continue  # Circles don't touch
              
                # Additional pruning: check if the connection might lead to target
                # Using weighted average position to estimate if path trends toward target
                weighted_x = current_x * next_radius + next_x * current_radius
                weighted_y = current_y * next_radius + next_y * current_radius
                total_radius = current_radius + next_radius
              
                if (weighted_x < total_radius * xCorner and 
                    weighted_y < total_radius * yCorner and 
                    depth_first_search(next_index)):
                    return True
          
            return False
      
        # Initialize visited array for DFS
        visited = [False] * len(circles)
      
        # Check each circle
        for index, (center_x, center_y, radius) in enumerate(circles):
            # If start or end point is inside a circle, path is impossible
            if (is_point_inside_circle(0, 0, center_x, center_y, radius) or 
                is_point_inside_circle(xCorner, yCorner, center_x, center_y, radius)):
                return False
          
            # If circle touches left/top boundary and creates a blocking path to right/bottom
            if (not visited[index] and 
                intersects_left_or_top_boundary(center_x, center_y, radius) and 
                depth_first_search(index)):
                return False
      
        # No blocking path found, so we can reach the corner
        return True
